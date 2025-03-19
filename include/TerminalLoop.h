/**
 * @file TerminalLoop.h
 * @brief Defines an abstract class for rendering logic that updates and prints at a set frequency.
 */


#pragma once


#include <chrono>
#include <thread>


#include "TerminalControl.h"


/**
 * @class TerminalLoop
 * @brief Abstract base class for terminal-based rendering loops.
 *
 * This class manages a continuous rendering loop that repeatedly updates the effect logic
 * and refreshes the terminal display. Derived classes must implement the `update()` method
 * to define custom behavior.
 */
class TerminalLoop
{
public:
    /**
     * @brief Constructs a terminal rendering loop.
     *
     * Initializes the terminal control and sets the desired frame rate.
     *
     * @param Height Initial height of the terminal grid.
     * @param Width Initial width of the terminal grid.
     * @param FrameRate Target frame rate (FPS) for the rendering loop. Defaults to 30.0 FPS.
     * @param scaleRatio Whether to maintain the aspect ratio when scaling the grid. Defaults to true.
     */
    TerminalLoop(size_t Height, size_t Width, double FrameRate = 30.0, bool scaleRatio = true);


    /**
     * @brief Starts the main loop, continuously updating and rendering the terminal.
     *
     * This function runs until 'Q'/'q' is inputed, calling `update()` and `render()` at the specified frame rate.
     */
    void run();

protected:
    TerminalControl terminal;   ///< Manages terminal size, clearing, and rendering.

    /**
     * @brief Updates the state of the effect.
     *
     * This pure virtual function must be implemented by derived classes to define
     * how the effect changes over time.
     */
    virtual void update() = 0;

    /**
     * @brief Renders the updated state to the terminal.
     *
     * Clears the terminal screen and prints the contents of the terminal grid.
     */
    void render();

private:
    double frameDuration;       ///< Time duration of each frame in milliseconds.
    const bool scaleRatio;      ///< Whether to maintain aspect ratio when resizing
};
