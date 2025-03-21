#include "TerminalEffects.h"


void TerminalEffects::changeBackgroundColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const Color & newColor)
{
    for (auto & row : terminalGrid)
        for (auto & symbol : row)
            symbol.backgroundColor.setColor(newColor);

    return;
}


void TerminalEffects::changeForegroundColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const Color & newColor)
{
    for (auto & row : terminalGrid)
        for (auto & symbol : row)
            symbol.foregroundColor.setColor(newColor);

    return;
}


void TerminalEffects::changeSymbolEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const char newSymbol)
{
    for (auto & row : terminalGrid)
        for (auto & symbol : row)
            symbol.symbol = newSymbol;

    return;
}


void TerminalEffects::changeTerminalToEffect(std::vector<std::vector<OneSymbol>> &terminalGrid, const char newSymbol, const Color &newForegroundColor, const Color &newBackgroundColor)
{
    for (auto & row : terminalGrid)
        for (auto & symbol : row)
        {
            symbol.foregroundColor.setColor(newForegroundColor);
            symbol.backgroundColor.setColor(newBackgroundColor);
            symbol.symbol = newSymbol;
        }

    return;
}


void TerminalEffects::invertColorEffect(std::vector<std::vector<OneSymbol>> &terminalGrid)
{
    for (auto & row : terminalGrid)
        for (auto & symbol : row)
            symbol.invertColor();

    return;
}


void TerminalEffects::adjustBrightnessByIncrementEffect(std::vector<std::vector<OneSymbol>> &terminalGrid, const double increment)
{
    for (auto & row : terminalGrid)
        for (auto & symbol : row)
        {
                symbol.backgroundColor.adjustColor(increment);
                symbol.foregroundColor.adjustColor(increment);
        }

    return;
}



void TerminalEffects::incrementColorEffect(std::vector<std::vector<OneSymbol>> &terminalGrid, const Color foregroundColorIncrement, const Color backgroundColorIncrement)
{
    for (auto & row : terminalGrid)
        for (auto & symbol : row)
        {
            symbol.foregroundColor.adjustColor(foregroundColorIncrement);
            symbol.backgroundColor.adjustColor(backgroundColorIncrement);
        }

    return;
}
