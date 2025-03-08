#pragma once

#include <sys/ioctl.h>
#include <unistd.h>


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

private:
    /**
     * @brief Width of the terminal in columns.
     */
    size_t width;

    /**
     * @brief Height of the terminal in rows.
     */
    size_t height;
};
