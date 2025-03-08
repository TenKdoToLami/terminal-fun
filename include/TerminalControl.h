#pragma once

#include <sys/ioctl.h>
#include <unistd.h>



class terminalControl
{
public:


    /**
     * @brief Gets the current terminal size (width and height).
     *
     * This function retrieves the current size of the terminal window
     * and stores the values in the `width` and `height` member variables.
     * It uses the `ioctl` system call to retrieve terminal information.
     *
     * @note This function only works for terminals that support the
     *       `TIOCGWINSZ` ioctl command.
     */
    void getTerminalSize();

private:
    /**
     * @brief Stores the width of the terminal.
     *
     * This variable stores the width (number of columns) of the terminal.
     */
    size_t width;

    /**
     * @brief Stores the height of the terminal.
     *
     * This variable stores the height (number of rows) of the terminal.
     */
    size_t height;
};