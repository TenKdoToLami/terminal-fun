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

void TerminalEffects::changeTerminalTo(std::vector<std::vector<OneSymbol>> &terminalGrid, const char newSymbol, const Color &newForegroundColor, const Color &newBackgroundColor)
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
    for (auto& row : terminalGrid)
        for (auto& symbol : row)
            symbol.invertColor();
    
    return;
}
