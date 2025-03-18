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

	double rowScale = (double)activeHeight / (double)height;
	double colScale = (double)activeWidth / (double)width;

	// Enforce equal scale if needed
	if (enforceEqualScale)
	{
		double uniformScale = std::max(rowScale, colScale);
		rowScale = uniformScale;
		colScale = uniformScale;
	}

	for (size_t i = 0; i < height; i++)
	{
		// Source row range
		double srcRowStart = (double)i * rowScale;
		double srcRowEnd = ((double)i + 1) * rowScale;

		for (size_t j = 0; j < width; j++)
		{
			// Source column range
			double srcColStart = (double)j * colScale;
			double srcColEnd = ((double)j + 1) * colScale;

			double sumWeight = 0.0;
			double red = 0.0, green = 0.0, blue = 0.0;

			// Iterate over affected source pixels
			size_t rowStart = (size_t)srcRowStart;
			size_t rowEnd = std::min((size_t)srcRowEnd, activeHeight - 1);
			size_t colStart = (size_t)srcColStart;
			size_t colEnd = std::min((size_t)srcColEnd, activeWidth - 1);

			for (size_t srcRow = rowStart; srcRow <= rowEnd; srcRow++)
			{
				for (size_t srcCol = colStart; srcCol <= colEnd; srcCol++)
				{
					// Compute overlapping area fraction
					double rowOverlap = std::min(srcRowEnd, (double)srcRow + 1.0) - std::max(srcRowStart, (double)srcRow);
					double colOverlap = std::min(srcColEnd, (double)srcCol + 1.0) - std::max(srcColStart, (double)srcCol);
					double weight = rowOverlap * colOverlap;

					// Accumulate weighted colors
					OneSymbol &sample = activeGrid[srcRow][srcCol];
					red += sample.backgroundColor.getR() * weight;
					green += sample.backgroundColor.getG() * weight;
					blue += sample.backgroundColor.getB() * weight;
					sumWeight += weight;
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
