/**
 * @file OneSymbol.h
 * @brief Defines the OneSymbol class for handling symbols with colors.
 *
 * The OneSymbol class represents a Unicode character with associated
 * foreground and background colors. It provides constructors for
 * initialization and a method to invert colors. The class also supports
 * output streaming for easy visualization.
 */


#pragma once


#include <iostream>


#include "Color.h"


/**
 * @class OneSymbol
 * @brief Represents a symbol with a character and associated foreground and background colors.
 *
 * This class allows the creation of a symbol that consists of a Unicode character and its associated
 * foreground and background colors. It also provides functionality to output the symbol to an output stream
 * with the specified colors.
 */
class OneSymbol
{
public:


    OneSymbol();

    
    /**
     * @brief Constructs a OneSymbol object with a given character and colors.
     *
     * This constructor initializes the symbol with a Unicode character and sets the foreground and background
     * colors for the symbol.
     *
     * @param Symbol The Unicode character to represent.
     * @param ForegroundColor The foreground color of the symbol.
     * @param BackgroundColor The background color of the symbol.
     */
    OneSymbol(const char Symbol, const Color & ForegroundColor, const Color & BackgroundColor);


    /**
     * @brief Constructs a OneSymbol object with only colors, defaulting the symbol to a space (' ').
     *
     * This constructor initializes the symbol to a space (' ') and sets the foreground and background
     * colors for the symbol.
     *
     * @param ForegroundColor The foreground color of the symbol.
     * @param BackgroundColor The background color of the symbol.
     */
    OneSymbol(const Color & ForegroundColor, const Color & BackgroundColor);


    /**
     * @brief Inverts the foreground and background colors of the symbol.
     *
     * This function inverts the foreground and background colors of the `OneSymbol` object 
     * by calling their respective `invertColor` methods.
     */
    void invertColor();


    /**
     * @brief Overloads the output stream operator to display a OneSymbol object.
     *
     * This friend function allows printing a `OneSymbol` object to an output stream (like `std::cout`),
     * showing the symbol with its associated foreground and background colors.
     *
     * @param os The output stream to which the symbol will be written.
     * @param oneSymbol The `OneSymbol` object to output.
     * @return The output stream with the formatted symbol.
     */
    friend std::ostream & operator << (std::ostream & os, const OneSymbol & oneSymbol);

    std::string toString() const;
//private:
    char symbol;                  ///< The character symbol represented by the OneSymbol object.
    Color foregroundColor;        ///< The foreground color of the symbol.
    Color backgroundColor;        ///< The background color of the symbol.
};
