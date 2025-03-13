#include "TerminalEffects.h"


void TerminalEffects::changeColorEffect(std::vector<std::vector<OneSymbol>> & terminalGrid, const Color & newColor) 
{
    for (auto& row : terminalGrid)
        for (auto& symbol : row)
            symbol.backgroundColor.setColor(newColor);
}


void TerminalEffects::invertColorEffect(std::vector<std::vector<OneSymbol>> & terminalGrid) 
{
    for (auto& row : terminalGrid)
        for (auto& symbol : row)
            symbol.backgroundColor.invertColor();
}
