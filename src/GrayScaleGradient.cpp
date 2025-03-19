#include "GrayScaleGradient.h"


GrayScaleGradient::GrayScaleGradient(double FrameRate, bool ScaleRatio)
    : TerminalLoop(DIMENSIONS, DIMENSIONS, FrameRate, ScaleRatio) 
{
    auto &grid = GRID(terminal);
    double increment = 255.0 / DIMENSIONS * 2;
    Color tmp(Colors::BLACK);
    for (size_t i = 0; i < DIMENSIONS / 2; i++)
    {
        for (size_t ii = 0; ii < DIMENSIONS; ii++)
            grid[i][ii].backgroundColor.setColor(tmp);
        
        tmp.adjustColor(Color(increment, increment, increment));
    }

    for (size_t i = DIMENSIONS / 2; i < DIMENSIONS; i++)
    {
        for (size_t ii = 0; ii < DIMENSIONS; ii++)
            grid[i][ii].backgroundColor.setColor(tmp);
        
        tmp.setRed(tmp.getR() - increment);
        tmp.setGreen(tmp.getG() - increment);
        tmp.setBlue(tmp.getB() - increment);
    }
        
    terminal.setUpScaledGrid(scaleRatio);
    terminal.printTerminal();

    return;
}
void GrayScaleGradient::update() 
{
    auto &grid = GRID(terminal);
    for (size_t i = 1; i < DIMENSIONS; i++)
        std::swap(grid[i],grid[i - 1]);    
    std::swap(grid.front(), grid.back());
    return;
};