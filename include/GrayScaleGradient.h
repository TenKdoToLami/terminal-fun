/**
 * @file GrayScaleGradient.h
 * @brief Defines a class for rendering a grayscale gradient effect in the terminal.
 */


#pragma once


#include "TerminalLoop.h"


/**
 * @class GrayScaleGradient
 * @brief Generates and displays a dynamic grayscale gradient.
 *
 * This class implements a smooth grayscale transition across the terminal grid.
 * The gradient updates over time, creating a simple animation effect.
 */
class GrayScaleGradient : public TerminalLoop
{
public:
    /**
     * @brief Constructs a grayscale gradient renderer.
     *
     * Initializes the terminal dimensions and frame rate.
     *
     * @param Height Terminal height.
     * @param Width Terminal width.
     * @param FrameRate Target frame rate for animation. Defaults to 30.0 FPS.
     * @param ScaleRatio Whether to maintain aspect ratio when scaling. Defaults to true.
     */
    GrayScaleGradient(double FrameRate = 30.0, bool ScaleRatio = true);


protected:
    /**
     * @brief Updates the grayscale gradient effect.
     *
     * Modifies the intensity of the gradient dynamically.
     */
    void update() override;
};
