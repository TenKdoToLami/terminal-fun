#include "RandomColors.h"

RandomColors::RandomColors(double FrameRate, bool ScaleRatio)
: TerminalLoop(DIMENSIONS, DIMENSIONS, FrameRate, ScaleRatio)
{
    std::srand(std::time(nullptr));
    auto &grid = GRID(terminal);
    
    for (size_t i = 0; i < DIMENSIONS; i++)
        for (size_t ii = 0; ii < DIMENSIONS; ii++)
            grid[i][ii].backgroundColor.setColor(Color(std::rand() % 256, std::rand() % 256, std::rand() % 256));
    
    terminal.setUpScaledGrid(scaleRatio);
    terminal.printTerminal();
    return;
}

void RandomColors::update()
{
    auto &grid = GRID(terminal);
    
    for (size_t i = 0; i < DIMENSIONS; i++)
        for (size_t ii = 0; ii < DIMENSIONS; ii++)
            grid[i][ii].backgroundColor.setColor(Color(std::rand() % 256, std::rand() % 256, std::rand() % 256));
    
    return;
}
