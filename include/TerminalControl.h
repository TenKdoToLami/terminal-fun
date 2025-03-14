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
     * @brief Constructor that sets up the terminal environment.
     *
     * This constructor disables cursor visibility and prevents input characters
     * from being echoed to the terminal.
     */
    TerminalControl();

    /**
     * @brief Destructor that restores the terminal settings.
     *
     * This destructor ensures the cursor is re-enabled and input character echoing
     * is restored when the object goes out of scope.
     */
    ~TerminalControl();


    /**
    * @brief Conversion operator to retrieve the terminal grid.
    *
    * This operator allows an instance of TerminalControl to be implicitly converted 
    * into a reference to a 2D vector of OneSymbol objects, representing the terminal's grid.
    * 
    * @return std::vector<std::vector<OneSymbol>>& A reference to the terminal grid.
    */
    operator std::vector < std::vector < OneSymbol > > & ();


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
     * @brief Clears the terminal screen.
     *
     * This method sends an ANSI escape sequence to move the cursor
     * to the home position and clear the screen. It is effective in
     * most UNIX-based terminals and ANSI-compatible environments.
     */
    void clearTerminal() const;


    /**
    * @brief Resizes the terminal grid to match the specified dimensions.
    *
    * This function adjusts the size of the `terminalGrid` to match the
    * current `height` and `width`. It ensures that each row is resized
    * correctly to maintain a consistent grid structure.
    *
    * @note Assumes `height` and `width` must be already set.
    */
    void setTerminalSize();


    /**
     * @brief Prints the terminal grid content to the output.
     *
     * This function iterates over the `terminalGrid` and prints each element
     * to the standard output.
    */
    void printTerminal() const;


private:
    size_t width;           ///< Width of the terminal in columns.
    size_t height;          ///< Height of the terminal in rows.

    std::vector < std::vector < OneSymbol > > terminalGrid;
};
