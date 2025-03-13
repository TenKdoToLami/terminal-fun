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

	for (size_t i = 0; i < height; i++)
		terminalGrid[i].resize(width);

	return;
}


void TerminalControl::printTerminal() const
{
	for (size_t i = 0; i < terminalGrid.size(); i++)
		for (size_t ii = 0; ii < terminalGrid.front().size(); ii++)
			std::cout << terminalGrid[i][ii];
	std::cout.flush();

	return;
}