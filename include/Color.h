#pragma once
/**
 * @file color.h
 * @brief Defines the Color struct and a set of predefined colors.
 *
 * This file provides a simple Color struct with red, green, and blue components.
 * It also defines a Colors namespace that contains commonly used colors categorized
 * by hue for easy reference.
 */


#include <cmath>
#include <algorithm>

/**
 * @brief Represents an RGB color.
 *
 * The Color struct stores RGB values as integers ranging from 0 to 255.
 * It is designed to be a lightweight, constexpr-compatible way to define colors.
 */
struct Color
{

    
    /**
     * @brief Constructs a Color with specified RGB values.
     *
     * @param Red Red component (0-255)
     * @param Green Green component (0-255)
     * @param Blue Blue component (0-255)
     */
    constexpr Color(double Red, double Green, double Blue) : red(Red), green(Green), blue(Blue) {};


    /**
     * @brief Retrieves the red component as an integer (0-255).
     *
     * @return int Rounded and clamped red value.
     */
    int getRed() const;


    /**
     * @brief Retrieves the green component as an integer (0-255).
     *
     * @return int Rounded and clamped green value.
     */
    int getGreen() const;


    /**
     * @brief Retrieves the blue component as an integer (0-255).
     *
     * @return int Rounded and clamped blue value.
     */
    int getBlue() const;


    /**
     * @brief Set a Color with specified RGB values.
     *
     * @param newColor Color(Red component (0-255), Green component (0-255), Blue component (0-255))
     */
    void setColor(Color newColor);


    /**
     * @brief Set a Color with specified RGB values.
     *
     * @param Red Red component (0-255)
     * @param Green Green component (0-255)
     * @param Blue Blue component (0-255)
     */
    void setColor(double Red, double Green, double Blue);

    /**
     * @brief Sets the red component.
     *
     * @param value New red value (0-255)
     */
    void setRed(double value);


    /**
     * @brief Sets the green component.
     *
     * @param value New green value (0-255)
     */
    void setGreen(double value);


    /**
     * @brief Sets the blue component.
     *
     * @param value New blue value (0-255)
     */
    void setBlue(double value);


    /**
     * @brief Inverts the red component.
     */
    void invertRed();


    /**
     * @brief Inverts the green component.
     */
    void invertGreen();


    /**
     * @brief Inverts the blue component.
     */
    void invertBlue();


    /**
     * @brief Inverts all color components.
     */
    void invertColor();


    /**
     * @brief Modifies the red component by a given coefficient.
     * @param coefficient Value to adjust the red component.
     */
    void modifyRed(double coefficient);


    /**
     * @brief Modifies the green component by a given coefficient.
     * @param coefficient Value to adjust the green component.
     */
    void modifyGreen(double coefficient);


    /**
     * @brief Modifies the blue component by a given coefficient.
     * @param coefficient Value to adjust the blue component.
     */
    void modifyBlue(double coefficient);


    /**
     * @brief Modifies all color components by a given coefficient.
     * @param coefficient Value to adjust all components.
     */
    void modifyColor(double coefficient);


private:
    double red;   ///< Red component (0-255)
    double green; ///< Green component (0-255)
    double blue;  ///< Blue component (0-255)
};

/**
 * @namespace Colors
 * @brief Contains predefined color constants.
 *
 * Colors are grouped into categories using Doxygen group tags for better documentation.
 */
namespace Colors
{
    extern const Color RED;
    extern const Color DARK_RED;
    extern const Color CORAL;
    extern const Color PINK;

    extern const Color GREEN;
    extern const Color LIME;
    extern const Color DARK_GREEN;
    extern const Color LIGHT_GREEN;
    extern const Color FOREST_GREEN;
    extern const Color MEDIUM_SEA_GREEN;

    extern const Color BLUE;
    extern const Color DARK_BLUE;
    extern const Color LIGHT_BLUE;
    extern const Color TURQUOISE;
    extern const Color AQUA;
    extern const Color TEAL;
    extern const Color SLATEGRAY;

    extern const Color YELLOW;
    extern const Color GOLD;
    extern const Color LIGHT_YELLOW;
    extern const Color IVORY;
    extern const Color BEIGE;

    extern const Color CYAN;
    extern const Color DARK_CYAN;

    extern const Color ORANGE;
    extern const Color DARK_ORANGE;
    extern const Color SADDLE_BROWN;
    extern const Color CHOCOLATE;

    extern const Color PURPLE;
    extern const Color INDIGO;
    extern const Color DARK_VIOLET;
    extern const Color VIOLET;
    extern const Color FUCHSIA;

    extern const Color BROWN;
    extern const Color TAN;
    extern const Color SILVER;
    extern const Color GRAY;
    extern const Color LIGHT_GRAY;
    extern const Color DARK_GRAY;

    extern const Color BLACK;
    extern const Color WHITE;

    extern const Color SNOW;
    extern const Color SEASHELL;
    extern const Color OLIVE;
}
