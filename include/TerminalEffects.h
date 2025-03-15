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
     * @brief Changes the background color of all symbols in the terminal grid.
     * 
     * This function iterates through the `terminalGrid` and updates the background 
     * color of each symbol to the specified `newColor`.
     * 
     * @param terminalGrid The terminal grid to modify.
     * @param newColor The new background color to apply.
     */
    void changeBackgroundColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const Color & newColor);


    /**
     * @brief Changes the foreground color of all symbols in the terminal grid.
     * 
     * This function updates the foreground color of each symbol in the `terminalGrid` 
     * to the specified `newColor`.
     * 
     * @param terminalGrid The terminal grid to modify.
     * @param newColor The new foreground color to apply.
     */
    void changeForegroundColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const Color & newColor);


    /**
     * @brief Changes the symbol character of all symbols in the terminal grid.
     * 
     * This function replaces the character of each symbol in the `terminalGrid` 
     * with the specified `newSymbol`.
     * 
     * @param terminalGrid The terminal grid to modify.
     * @param newSymbol The new symbol character to apply.
     */
    void changeSymbolEffect(std::vector < std::vector <OneSymbol> > & terminalGrid, const char newSymbol);


    /**
     * @brief Changes the entire terminal grid to a new symbol and colors.
     * 
     * This function updates each symbol in the `terminalGrid` to have the specified 
     * `newSymbol`, `newForegroundColor`, and `newBackgroundColor`.
     * 
     * @param terminalGrid The terminal grid to modify.
     * @param newSymbol The new symbol character to apply.
     * @param newForegroundColor The new foreground color to apply.
     * @param newBackgroundColor The new background color to apply.
     */
    void changeTerminalTo(std::vector < std::vector <OneSymbol> > & terminalGrid, const char newSymbol, const Color & newForegroundColor, const Color & newBackgroundColor);



    /**
     * @brief Inverts all symbols in the terminal grid.
     *  
     * @param terminalGrid The terminal grid to modify.
     */
    void invertColorEffect(std::vector < std::vector <OneSymbol> > & terminalGrid);
}
