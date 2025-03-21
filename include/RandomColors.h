/**
 * @file RandomColors.h
 * @brief Defines a class for rendering a random color grid effect in the terminal.
 */


#pragma once


#include "TerminalLoop.h"


/**
 * @class RandomColors
 * @brief Generates and displays a grid of randomly colored cells.
 *
 * This class populates the terminal grid with random colors,
 * updating over time for a dynamic effect.
 */
class RandomColors : public TerminalLoop
{
public:
    /**
     * @brief Constructs a random color grid renderer.
     *
     * Initializes the terminal dimensions and frame rate.
     *
     * @param FrameRate Target frame rate for animation. Defaults to 30.0 FPS.
     * @param ScaleRatio Whether to maintain aspect ratio when scaling. Defaults to true.
     */
    RandomColors(double FrameRate = 30.0, bool ScaleRatio = true);

protected:
    /**
     * @brief Updates the grid with new random colors.
     *
     * Each frame, the grid's colors are randomized again.
     */
    void update() override;
};