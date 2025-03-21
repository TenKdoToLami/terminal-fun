/**
 * @file MainMenu.h
 * @brief Defines the main menu system for the Terminal Graphics Demo.
 */


#pragma once


#include <string>
#include <vector>
#include <functional>

#include "RandomColors.h"
#include "GrayScaleGradient.h"

/**
 * @struct MenuOption
 * @brief Represents a menu option with a name and an associated action.
 */
struct MenuOption
{
    std::string name;             ///< Name of the menu option.
    std::function<void()> action; ///< Function to execute when the option is selected.
};


/**
 * @brief Displays the main menu and prompts user input.
 *
 * @param options A vector of available menu options.
 */
void displayMenu(const std::vector<MenuOption> &options);


/**
 * @brief Runs the main menu loop.
 *
 * This function keeps displaying the menu and processing user input
 * until the user chooses to exit.
 */
void runMainMenu();
