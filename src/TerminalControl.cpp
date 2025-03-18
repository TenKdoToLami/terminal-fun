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

	for (size_t i = 0; i < height; i++)
	{
		double srcRowF = (double) i * rowScale;
		size_t srcRow = (size_t) srcRowF;
		double rowFrac = srcRowF - (double) srcRow;

		for (size_t j = 0; j < width; j++)
		{
			double srcColF = (double) j * colScale;
			size_t srcCol = (size_t) srcColF;
			double colFrac = srcColF - (double) srcCol;

			// Get the four closest values
			OneSymbol &topLeft = activeGrid[srcRow][srcCol];
			OneSymbol &topRight = (srcCol + 1 < activeWidth) ? activeGrid[srcRow][srcCol + 1] : topLeft;
			OneSymbol &bottomLeft = (srcRow + 1 < activeHeight) ? activeGrid[srcRow + 1][srcCol] : topLeft;
			OneSymbol &bottomRight = (srcRow + 1 < activeHeight && srcCol + 1 < activeWidth) ? activeGrid[srcRow + 1][srcCol + 1] : topLeft;

			// Compute bilinear interpolation weights for each color channel
			scaledGrid[i][j].backgroundColor.setRed(
				topLeft.backgroundColor.getR() * (1 - rowFrac) * (1 - colFrac)
				+ topRight.backgroundColor.getR() * (1 - rowFrac) * colFrac
				+ bottomLeft.backgroundColor.getR() * rowFrac * (1 - colFrac)
				+ bottomRight.backgroundColor.getR() * rowFrac * colFrac
			);
			
			scaledGrid[i][j].backgroundColor.setGreen(
				topLeft.backgroundColor.getG() * (1 - rowFrac) * (1 - colFrac)
				+ topRight.backgroundColor.getG() * (1 - rowFrac) * colFrac
				+ bottomLeft.backgroundColor.getG() * rowFrac * (1 - colFrac)
				+ bottomRight.backgroundColor.getG() * rowFrac * colFrac
			);
			
			scaledGrid[i][j].backgroundColor.setBlue(
				topLeft.backgroundColor.getB() * (1 - rowFrac) * (1 - colFrac)
				+ topRight.backgroundColor.getB() * (1 - rowFrac) * colFrac
				+ bottomLeft.backgroundColor.getB() * rowFrac * (1 - colFrac)
				+ bottomRight.backgroundColor.getB() * rowFrac * colFrac
			);
		}
	}
}