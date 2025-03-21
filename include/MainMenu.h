/**
 * @file mainMenu.h
 * @brief Defines the main menu system for the Terminal Graphics Demo.
 */


#pragma once


#include <vector>
#include <functional>
#include <iostream>


#include "RandomColors.h"
#include "GrayScaleGradient.h"
#include "OneSymbol.h"


/**
 * @struct MenuOption
 * @brief Represents a menu option with a name and an associated action.
 */
struct MenuOption
{
    std::vector <OneSymbol> text;  ///< Name of the menu option as colored text.
    std::function <void()> action; ///< Function to execute when the option is selected.
};


/**
 * @brief Displays the main menu with color support.
 *
 * @param options A vector of available menu options.
 */
void displayMenu(const std::vector <MenuOption> & options);


/**
 * @brief Runs the main menu loop.
 *
 * This function keeps displaying the menu and processing user input
 * until the user chooses to exit.
 */
void runMainMenu();


/**
 * @brief Converts a std::string to a std::vector<OneSymbol> with specified colors.
 *
 * @param text The string to convert.
 * @param fgColor The foreground color to apply to each character.
 * @param bgColor The background color to apply to each character.
 * @return std::vector<OneSymbol> The vector containing colored symbols.
 */
std::vector <OneSymbol> stringToOneSymbolVector(const std::string & text, const Color & fgColor, const Color & bgColor);


/**
 * @brief Overloads the stream operator to print a vector of OneSymbol.
 *
 * @param os The output stream.
 * @param text The vector of OneSymbol objects to print.
 * @return std::ostream& The modified output stream.
 */
std::ostream & operator<<(std::ostream & os, const std::vector <OneSymbol> & text);