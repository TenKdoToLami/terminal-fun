#include "TerminalControl.h"


TerminalControl::TerminalControl(const size_t Height, const size_t Width)
{
	activeGrid.resize(Height);
	for (size_t i = 0; i < Height; i++)
		activeGrid[i].resize(Width);

	// Disable cursor visibility
	std::cout << "\033[?25l";
	std::cout.flush();

	// Disable input character echoing
	struct termios tty;
	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag &= tcflag_t(~ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}


TerminalControl::~TerminalControl()
{
	// Re-enable cursor visibility
	std::cout << "\033[?25h";
	std::cout.flush();

	// Restore input character echoing
	struct termios tty;
	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}


TerminalControl::operator std::vector <std::vector<OneSymbol> > & ()
{
	return activeGrid;
}


void TerminalControl::getTerminalSize()
{
	struct winsize w;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
	{
		width = w.ws_col;
		height = w.ws_row;
	}

	return;
}


void TerminalControl::clearTerminal() const
{
	std::cout << "\033[H";		///< Move cursor to home and clear screen
	std::cout.flush();
	
	return;
}


void TerminalControl::setTerminalSize()
{
	scaledGrid.resize(height);
	for (size_t i = 0; i < height; i++)
		scaledGrid[i].resize(width);

	return;
}


void TerminalControl::printTerminal() const
{
	for (size_t i = 0; i < scaledGrid.size(); i++)
		for (size_t ii = 0; ii < scaledGrid.front().size(); ii++)
			std::cout << scaledGrid[i][ii];
	std::cout.flush();

	return;
}



void TerminalControl::setUpScaledGrid(bool enforceEqualScale)
{
	getTerminalSize();
	setTerminalSize();

	size_t activeHeight = activeGrid.size();
	size_t activeWidth = activeGrid.empty() ? 0 : activeGrid[0].size();

	if (activeHeight == 0 || activeWidth == 0)
		return;

	double rowScale = (double) activeHeight / (double) height;
	double colScale = (double) activeWidth / (double) width;

	// If enforcing equal scale, use the larger of the two
	if (enforceEqualScale)
	{
		double uniformScale = std::max(rowScale, colScale);
		rowScale = uniformScale;
		colScale = uniformScale;
	}

	// Lanczos kernel with parameter a = 3 (uses 3 pixels in each direction)
	auto Lanczos = [](double x, int a = 3) -> double
	{
		if (x == 0.0) return 1.0;
		if (x < -a || x > a) return 0.0;
		double piX = M_PI * x;
		return (a * sin(piX) * sin(piX / a)) / (piX * piX);
	};

	for (size_t i = 0; i < height; i++)
	{
		double srcRowF = (double) i * rowScale;
		size_t srcRow = (size_t) srcRowF;

		for (size_t j = 0; j < width; j++)
		{
			double srcColF = (double) j * colScale;
			size_t srcCol = (size_t) srcColF;

			double sumWeight = 0.0;
			double red = 0.0, green = 0.0, blue = 0.0;

			// Lanczos sampling over a 3x3 neighborhood
			for (int m = -2; m <= 2; m++)
			{
				for (int n = -2; n <= 2; n++)
				{
					int sampleRow = std::clamp<int>((int)srcRow + m, 0, (int)activeHeight - 1);
					int sampleCol = std::clamp<int>((int)srcCol + n, 0, (int)activeWidth - 1);

					double weight = Lanczos((double)m - (srcRowF - (double)srcRow)) * Lanczos((double)n - (srcColF - (double)srcCol));
					sumWeight += weight;

					OneSymbol &sample = activeGrid[(size_t)sampleRow][(size_t)sampleCol];
					red += sample.backgroundColor.getR() * weight;
					green += sample.backgroundColor.getG() * weight;
					blue += sample.backgroundColor.getB() * weight;
				}
			}

			// Normalize colors
			if (sumWeight > 0.0)
			{
				red /= sumWeight;
				green /= sumWeight;
				blue /= sumWeight;
			}

			// Assign to scaled grid
			scaledGrid[i][j].backgroundColor.setRed(std::clamp(red, 0.0, 255.0));
			scaledGrid[i][j].backgroundColor.setGreen(std::clamp(green, 0.0, 255.0));
			scaledGrid[i][j].backgroundColor.setBlue(std::clamp(blue, 0.0, 255.0));
		}
	}
}
