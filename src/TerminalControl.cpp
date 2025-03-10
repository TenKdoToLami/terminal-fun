#include "TerminalControl.h"


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
	terminalGrid.resize(height);

	for (int i = 0; i < height; i++)
		terminalGrid[i].resize(width);

	return;
}
