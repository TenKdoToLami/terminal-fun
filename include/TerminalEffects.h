#pragma once


#include <vector>
#include <functional>
#include "OneSymbol.h"


using TerminalEffect = std::function <void (std::vector < std::vector <OneSymbol> > &)>;


/**
 * @namespace TerminalEffects
 * @brief Contains functions that modify the terminal grid in various ways.
 */
namespace TerminalEffects 
{
    /**
     * @brief Changes the color of all symbols in the terminal grid.
     * 
     * @param terminalGrid The terminal grid to modify.
     * @param newColor The Color to change terminalGrid to.
     */
    void changeColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const Color & newColor);


    /**
     * @brief Inverts all symbols in the terminal grid.
     *  
     * @param terminalGrid The terminal grid to modify.
     */
    void invertColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid);
}
