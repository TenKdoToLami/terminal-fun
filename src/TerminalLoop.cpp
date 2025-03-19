#include "TerminalLoop.h"


TerminalLoop::TerminalLoop(size_t Height, size_t Width, double FrameRate, bool ScaleRatio)
    : terminal(Height, Width), scaleRatio(ScaleRatio), frameDuration(1000.0 / FrameRate) {}


void TerminalLoop::run()
{
    while (true)
    {
        char ch;
        if (read(STDIN_FILENO, &ch, 1) > 0 && (ch == 'Q' || ch == 'q'))
            return;
        
        auto startTime = std::chrono::high_resolution_clock::now();

        update();
        render();

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = endTime - startTime;

        if (elapsed.count() < frameDuration)
            std::this_thread::sleep_for(std::chrono::milliseconds((long)(frameDuration - elapsed.count())));
    }

    return;
}


void TerminalLoop::render()
{
    terminal.setUpScaledGrid(scaleRatio);
    terminal.clearTerminal();
    terminal.printTerminal();

    return;
}
