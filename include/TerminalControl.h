/**
 * @file TerminalControl.h
 * @brief Terminal control utilities for handling terminal size and output.
 */


#pragma once


#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <termios.h>


#include "OneSymbol.h"


#define GRID(terminal) (static_cast<std::vector<std::vector<OneSymbol>>&>(terminal))


/**
 * @class TerminalControl
 * @brief A class to manage terminal size and output.
 *
 * This class provides functionalities to retrieve the terminal size,
 * clear the terminal screen, resize the terminal grid, and print its contents.
 */
class TerminalControl
{
public:
    /**
     * @brief Constructor that sets up the terminal environment and initializes the active grid.
     *
     * This constructor disables cursor visibility, prevents input characters
     * from being echoed to the terminal, and resizes the active grid.
     *
     * @param Height The initial height of the active grid.
     * @param Width The initial width of the active grid.
     */
    TerminalControl(const size_t Height, const size_t Width);

    /**
     * @brief Destructor that restores the terminal settings.
     *
     * This destructor ensures the cursor is re-enabled and input character echoing
     * is restored when the object goes out of scope.
     */
    ~TerminalControl();


    /**
    * @brief Conversion operator to retrieve the active terminal grid.
    *
    * This operator allows an instance of TerminalControl to be implicitly converted
    * into a reference to a 2D vector of OneSymbol objects, representing the active grid.
    *
    * @return std::vector<std::vector<OneSymbol>>& A reference to the active grid.
    */
    operator std::vector < std::vector < OneSymbol > > & ();


    /**
     * @brief Clears the terminal screen.
     *
     * This method sends an ANSI escape sequence to move the cursor
     * to the home position and clear the screen. It is effective in
     * most UNIX-based terminals and ANSI-compatible environments.
     */
    void clearTerminal() const;


    /**
     * @brief Prints the scaled terminal grid content to the output.
     *
     * This function iterates over `scaledGrid` and prints each element
     * to the standard output.
     */
    void printTerminal() const;


    std::string toString() const;

    /**
     * @brief Adjusts the scaled grid to fit the current terminal size.
     *
     * This function retrieves the current terminal size, resizes `scaledGrid`
     * accordingly, and scales `activeGrid` to fit within it.
     *
     * @param scaleRatio If true, scales proportionally; otherwise, scales uniformly.
     *
     * @note Assumes `activeGrid` is non-empty.
     */
    void setUpScaledGrid(bool scaleRatio = true);


private:
    size_t width;           ///< Width of the terminal in columns.
    size_t height;          ///< Height of the terminal in rows.

    std::vector < std::vector < OneSymbol > > activeGrid;  ///< The main grid being modified (Also referenced as terminalGrid)
    std::vector < std::vector < OneSymbol > > scaledGrid;  ///< The scaled grid used for printing


    /**
    * @brief Resizes the scaled grid to match the specified dimensions.
    *
    * This function adjusts the size of `scaledGrid` to match the
    * current `height` and `width`. It ensures that each row is resized
    * correctly to maintain a consistent grid structure.
    *
    * @note Assumes `height` and `width` must be already set.
    */
    void setTerminalSize();


    /**
     * @brief Retrieves the current terminal size.
     *
     * This function queries the terminal for its current dimensions (columns and rows)
     * and updates the `width` and `height` member variables accordingly.
     *
     * @note This function is platform-dependent and only works on terminals that
     *       support the `TIOCGWINSZ` ioctl command (POSIX systems).
     */
    void getTerminalSize();


    /**
     * @brief Computes scaling factors for row and column adjustments.
     *
     * @param rowScale Reference to store the computed row scaling factor.
     * @param colScale Reference to store the computed column scaling factor.
     * @param scaleRatio If true, maintains the aspect ratio while scaling.
     */
    void computeScalingFactors(double & rowScale, double & colScale, bool scaleRatio) const;


    /**
     * @brief Computes the source row range for scaling.
     *
     * @param i Row index in the scaled grid.
     * @param rowScale Scaling factor for rows.
     * @param srcRowStart Reference to store the computed source row start.
     * @param srcRowEnd Reference to store the computed source row end.
     */
    void getSourceRowRange(size_t i, double rowScale, double & srcRowStart, double & srcRowEnd) const;


    /**
     * @brief Computes the source column range for scaling.s
     *
     * @param j Column index in the scaled grid.
     * @param colScale Scaling factor for columns.
     * @param srcColStart Reference to store the computed source column start.
     * @param srcColEnd Reference to store the computed source column end.
     */
    void getSourceColRange(size_t j, double colScale, double & srcColStart, double & srcColEnd) const;


    /**
     * @brief Determines the source bounds for mapping grid values.
     *
     * @param srcRowStart Source row start position.
     * @param srcRowEnd Source row end position.
     * @param srcColStart Source column start position.
     * @param srcColEnd Source column end position.
     * @param rowStart Reference to store computed row start index.
     * @param rowEnd Reference to store computed row end index.
     * @param colStart Reference to store computed column start index.
     * @param colEnd Reference to store computed column end index.
     */
    void getSourceBounds(double srcRowStart, double srcRowEnd, double srcColStart, double srcColEnd,
                         size_t & rowStart, size_t & rowEnd, size_t & colStart, size_t & colEnd) const;

    /**
     * @brief Computes the averaged color values for scaling.
     *
     * @param rowStart Start row index in activeGrid.
     * @param rowEnd End row index in activeGrid.
     * @param colStart Start column index in activeGrid.
     * @param colEnd End column index in activeGrid.
     * @param srcRowStart Source row start position.
     * @param srcRowEnd Source row end position.
     * @param srcColStart Source column start position.
     * @param srcColEnd Source column end position.
     * @param red Reference to store computed red color value.
     * @param green Reference to store computed green color value.
     * @param blue Reference to store computed blue color value.
     */
    void computeAveragedColor(size_t rowStart, size_t rowEnd, size_t colStart, size_t colEnd,
                              double srcRowStart, double srcRowEnd, double srcColStart,
                              double srcColEnd, Color & computedColor) const;
};
