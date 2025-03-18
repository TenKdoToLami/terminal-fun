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


    /**
     * @brief Adjusts the scaled grid to fit the current terminal size.
     *
     * This function retrieves the current terminal size, resizes `scaledGrid`
     * accordingly, and scales `activeGrid` to fit within it.
     *
     * The scaling uses a nearest-neighbor approach:
     * - If `activeGrid` is larger than `scaledGrid`, it shrinks by selecting the closest matching symbols.
     * - If `activeGrid` is smaller, it expands by duplicating the nearest symbols.
     *
     * The function ensures that `scaledGrid` is properly populated, preventing
     * out-of-bounds access when mapping between `activeGrid` and `scaledGrid`.
     *
     * @note Assumes `activeGrid` is non-empty.
     */
    void setUpScaledGrid();


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
};
