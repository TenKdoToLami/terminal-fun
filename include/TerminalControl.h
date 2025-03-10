#pragma once


#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>


#include "OneSymbol.h"

class TerminalControl
{
public:
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

private:
    size_t width;           ///< Width of the terminal in columns.
    size_t height;          ///< Height of the terminal in rows.

    std::vector < std::vector < OneSymbol > > terminalGrid;
};
