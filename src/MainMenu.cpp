/**
 * @file mainMenu.cpp
 * @brief Implements the main menu system for the Terminal Graphics Demo.
 */


#include "MainMenu.h"


void displayMenu(const std::vector<MenuOption> &options)
{
    std::vector <OneSymbol> headerText = stringToOneSymbolVector("Welcome to ", Colors::WHITE, Colors::BLACK);
    std::vector <OneSymbol> titleText = stringToOneSymbolVector("Terminal Graphics Demo!", Colors::CYAN, Colors::BLACK);
    std::cout 
        << headerText
        << titleText
        << "\nselect an option:\n";

    for (size_t i = 0; i < options.size(); i++)
    {
        std::cout << i << ". ";
        std::cout << options[i].text;
    }

    std::vector<OneSymbol> exitText = stringToOneSymbolVector("Q. Exit", Colors::RED, Colors::BLACK);
    std::cout <<exitText;

    std::cout << "Enter your choice: ";
}


void runMainMenu()
{
    bool running = true;

    std::vector <MenuOption> menuOptions =
    {
        {
            stringToOneSymbolVector("Random Colors Grid", Colors::GREEN, Colors::BLACK),[]() 
            { 
                RandomColors randomColors; randomColors.run(); 
            }
        },
        {
            stringToOneSymbolVector("Grayscale Gradient", Colors::GRAY, Colors::BLACK),[]() 
            { 
                GrayScaleGradient grayScale; grayScale.run(); 
            }
        }
    };

    while (running)
    {
        displayMenu(menuOptions);
        std::string choice;
        std::cin >> choice;

        if (choice == "Q" || choice == "q")
        {
            running = false;
            std::cout << stringToOneSymbolVector("Exiting the program.", Colors::RED, Colors::BLACK);
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


std::vector <OneSymbol> stringToOneSymbolVector(const std::string & text, const Color & fgColor, const Color & bgColor)
{
    std::vector <OneSymbol> result;
    result.reserve(text.size());

    for (char ch : text)
    {
        result.emplace_back(ch, fgColor, bgColor);
    }

    return result;
}


std::ostream & operator <<(std::ostream & os, const std::vector <OneSymbol> & text)
{
    for (const auto & symbol : text)
    {
        os << symbol;
    }
    os << "\n";
    return os;
}
