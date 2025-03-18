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


void TerminalControl::setUpScaledGrid()
{
	getTerminalSize();
	setTerminalSize();

	size_t activeHeight = activeGrid.size();
	size_t activeWidth = activeGrid.empty() ? 0 : activeGrid[0].size();

	double rowScale = (double) activeHeight / (double) height;
	double colScale = (double) activeWidth / (double) width;

	for (size_t i = 0; i < height; i++)
	{
		size_t srcRow = (size_t) ((double) i * rowScale);
		for (size_t j = 0; j < width; j++)
		{
			size_t srcCol = (size_t) ((double) j * colScale);
			scaledGrid[i][j] = activeGrid[srcRow][srcCol];
		}
	}

	return;
}