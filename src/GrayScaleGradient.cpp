#include "GrayScaleGradient.h"


GrayScaleGradient::GrayScaleGradient(double FrameRate, bool ScaleRatio)
    : TerminalLoop(DIMENSIONS, DIMENSIONS, FrameRate, ScaleRatio) 
{
    auto &grid = GRID(terminal);
    double increment = 255 / DIMENSIONS;
    Color tmp(Colors::BLACK);
    for (size_t i = 0; i < DIMENSIONS; i++)
    {
        for (size_t ii = 0; ii < DIMENSIONS; ii++)
            grid[i][ii].backgroundColor.setColor(tmp);
        
        tmp.adjustColor(Color(increment, increment, increment));
    }

    return;
}
void GrayScaleGradient::update() 
{
};