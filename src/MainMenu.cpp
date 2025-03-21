/**
 * @file mainMenu.cpp
 * @brief Implements the main menu system for the Terminal Graphics Demo.
 */


#include "MainMenu.h"



void displayMenu(const std::vector<MenuOption> &options)
{
    std::cout << "Welcome to the Terminal Graphics Demo!\n\n";
    std::cout << "Select an option:\n";

    for (size_t i = 0; i < options.size(); i++)
    {
        std::cout << i << ". " << options[i].name << std::endl;
    }

    std::cout << "Q. Exit\n";
    std::cout << "Enter your choice: ";
}


/**
 * @brief Runs the main menu loop.
 *
 * The function continuously displays the menu, processes user input,
 * and executes selected actions until the user chooses to exit.
 */
void runMainMenu()
{
    bool running = true;
    std::vector<MenuOption> menuOptions =
        {
            {"Random Colors Grid", []()
             { RandomColors randomColors; randomColors.run(); }},
            {"Grayscale Gradient", []()
             { GrayScaleGradient grayScale; grayScale.run(); }}};

    while (running)
    {
        displayMenu(menuOptions);
        std::string choice;
        std::cin >> choice;

        if (choice == "Q" || choice == "q")
        {
            running = false;
            std::cout << "Exiting the program. Goodbye!" << std::endl;
        }
        else
        {
            try
            {
                int index = std::stoi(choice);
                if (index >= 0 && index < static_cast<int>(menuOptions.size()))
                {
                    menuOptions[(size_t)index].action();
                }
                else
                {
                    std::cout << "Invalid choice. Please try again.\n";
                }
            }
            catch (const std::invalid_argument &)
            {
                std::cout << "Invalid input. Please enter a valid number or 'Q' to quit.\n";
            }
        }
    }
}
