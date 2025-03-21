/**
 * @file TerminalControl.cpp
 * @brief Implementation of terminal control functionalities.
 */


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
	tty.c_lflag &= tcflag_t(~ICANON);
	tty.c_cc[VMIN] = 0;
	tty.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}


TerminalControl::~TerminalControl()
{
	// Re-enable cursor visibility
	std::cout << "\033[?25h";
	std::cout.flush();

	clearTerminal();
	// Restore input character echoing
	struct termios tty;
	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag |= ECHO | ICANON;
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



void TerminalControl::setUpScaledGrid(bool scaleRatio)
{
	getTerminalSize();
	setTerminalSize();

	double rowScale, colScale;
	computeScalingFactors(rowScale, colScale, scaleRatio);
	
	#pragma omp target teams distribute parallel for collapse(2)
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			double srcRowStart, srcRowEnd;
			getSourceRowRange(i, rowScale, srcRowStart, srcRowEnd);

			double srcColStart, srcColEnd;
			getSourceColRange(j, colScale, srcColStart, srcColEnd);

			size_t rowStart, rowEnd, colStart, colEnd;
			getSourceBounds(srcRowStart, srcRowEnd, srcColStart, srcColEnd, rowStart, rowEnd, colStart, colEnd);

			Color computedColor(0,0,0);
			computeAveragedColor(rowStart, rowEnd, colStart, colEnd, srcRowStart, srcRowEnd, srcColStart, srcColEnd, computedColor);

			scaledGrid[i][j].backgroundColor.setColor(computedColor);
		}
	}

	return;
}

void TerminalControl::computeScalingFactors(double & rowScale, double & colScale, bool scaleRatio) const
{
	rowScale = (double)activeGrid.size() / (double)height;
	colScale = (double)activeGrid[0].size() / (double)width;

	if (scaleRatio)
		return;
	
	double uniformScale = std::max(rowScale, colScale);
	rowScale = uniformScale;
	colScale = uniformScale;

	return;
}

void TerminalControl::getSourceRowRange(size_t i, double rowScale, double & srcRowStart, double & srcRowEnd) const
{
	srcRowStart = (double)i * rowScale;
	srcRowEnd = ((double)i + 1) * rowScale;

	return;
}

void TerminalControl::getSourceColRange(size_t j, double colScale, double &srcColStart, double &srcColEnd) const
{
	srcColStart = (double)j * colScale;
	srcColEnd = ((double)j + 1) * colScale;

	return;
}

void TerminalControl::getSourceBounds(double srcRowStart, double srcRowEnd, double srcColStart, double srcColEnd,
									  size_t & rowStart, size_t & rowEnd, size_t & colStart, size_t & colEnd) const
{
	rowStart = (size_t)srcRowStart;
	rowEnd = std::min((size_t)srcRowEnd, activeGrid.size() - 1);
	colStart = (size_t)srcColStart;
	colEnd = std::min((size_t)srcColEnd, activeGrid[0].size() - 1);

	return;
}

void TerminalControl::computeAveragedColor(size_t rowStart, size_t rowEnd, size_t colStart, size_t colEnd,
										   double srcRowStart, double srcRowEnd, double srcColStart,
										   double srcColEnd, Color &computedColor) const
{
	double sumWeight = 0.0;
	double rSum = 0.0, gSum = 0.0, bSum = 0.0; // Avoid multiple function calls

	for (size_t srcRow = rowStart; srcRow <= rowEnd; ++srcRow)
	{
		double rowOverlap = std::min(srcRowEnd, srcRow + 1.0) - std::max(srcRowStart, static_cast<double>(srcRow));

		for (size_t srcCol = colStart; srcCol <= colEnd; ++srcCol)
		{
			double colOverlap = std::min(srcColEnd, srcCol + 1.0) - std::max(srcColStart, static_cast<double>(srcCol));
			double weight = rowOverlap * colOverlap;

			const OneSymbol &sample = activeGrid[srcRow][srcCol]; // Use reference to avoid copying
			rSum += sample.backgroundColor.getR() * weight;
			gSum += sample.backgroundColor.getG() * weight;
			bSum += sample.backgroundColor.getB() * weight;
			sumWeight += weight;
		}
	}

	if (sumWeight > 0.0)
	{
		computedColor.setRed(rSum / sumWeight);
		computedColor.setGreen(gSum / sumWeight);
		computedColor.setBlue(bSum / sumWeight);
	}
}
