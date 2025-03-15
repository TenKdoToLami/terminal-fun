#pragma once


#include <vector>
#include <functional>
#include "OneSymbol.h"



/**
 * @namespace TerminalEffects
 * @brief Contains functions that modify the terminal grid in various ways.
 */
namespace TerminalEffects 
{
    /**
     * @brief Changes the color of background in the terminal grid.
     * 
     * @param terminalGrid The terminal grid to modify.
     * @param newColor The Color to change the background of terminalGrid to.
     */
    void changeBackgroundColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const Color & newColor);


    /**
     * @brief Changes the color of all symbols in the terminal grid.
     * 
     * @param terminalGrid The terminal grid to modify.
     * @param newColor The Color to change the symbols of terminalGrid to.
     */
    void changeForegroundColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const Color & newColor);


    /**
     * @brief Changes the symbols in the terminal grid.
     * 
     * @param terminalGrid The terminal grid to modify.
     * @param newSymbolk The symbol to change terminalGrid to.
     */
    void changeSymbolEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const char newSymbol);






    /**
     * @brief Inverts all symbols in the terminal grid.
     *  
     * @param terminalGrid The terminal grid to modify.
     */
    void invertColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid);
}
