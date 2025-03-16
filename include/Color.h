#pragma once
/**
 * @file Color.h
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
     * @brief Checks if two colors are equal.
     * 
     * @param other The color to compare with.
     * @return True if the colors are the same, false otherwise.
     */
    bool operator == (const Color & other) const;


    /**
     * @brief Checks if two colors are different.
     * 
     * @param other The color to compare with.
     * @return True if the colors are different, false otherwise.
     */
    bool operator != (const Color & other) const;

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
     * @brief Retrieves the red component as a double.
     * 
     * Returns the raw red component value without clamping or rounding.
     * This allows precise operations without integer constraints.
     * 
     * @return double The red component value.
     */
    double getR() const;


    /**
     * @brief Retrieves the blue component as a double.
     * 
     * Returns the raw blue component value without clamping or rounding.
     * This allows precise operations without integer constraints.
     * 
     * @return double The blue component value.
     */
    double getB() const;


    /**
     * @brief Retrieves the green component as a double.
     * 
     * Returns the raw green component value without clamping or rounding.
     * This allows precise operations without integer constraints.
     * 
     * @return double The green component value.
     */
    double getG() const;

    
    /**
     * @brief Set a Color with specified RGB values.
     *
     * @param newColor Color(Red component (0-255), Green component (0-255), Blue component (0-255))
     */
    void setColor(const Color newColor);


    /**
     * @brief Set a Color with specified RGB values.
     *
     * @param Red Red component (0-255)
     * @param Green Green component (0-255)
     * @param Blue Blue component (0-255)
     */
    void setColor(const double Red, const double Green, const double Blue);

    /**
     * @brief Sets the red component.
     *
     * @param value New red value (0-255)
     */
    void setRed(const double value);


    /**
     * @brief Sets the green component.
     *
     * @param value New green value (0-255)
     */
    void setGreen(const double value);


    /**
     * @brief Sets the blue component.
     *
     * @param value New blue value (0-255)
     */
    void setBlue(const double value);


    /**
     * @brief Inverts the red component.
     * 
     * Reverses the intensity of the red component by subtracting its current value from 255.
     * This creates a complementary color effect, ensuring the red component moves toward the opposite end of the spectrum.
     * The result is clamped within the valid range [0, 255].
     */
    void invertRed();

    
    /**
     * @brief Inverts the green component.
     * 
     * Reverses the intensity of the green component by subtracting its current value from 255.
     * This produces a complementary color effect, ensuring the green component moves toward the opposite end of the spectrum.
     * The result is clamped within the valid range [0, 255].
     */
    void invertGreen();


    /**
     * @brief Inverts the blue component.
     * 
     * Reverses the intensity of the blue component by subtracting its current value from 255.
     * This generates a complementary color effect, ensuring the blue component moves toward the opposite end of the spectrum.
     * The result is clamped within the valid range [0, 255].
     */
    void invertBlue();


    /**
     * @brief Inverts all color components.
     * 
     * Applies the inversion operation to the red, green, and blue components.
     * This results in a full-color inversion, producing a negative of the original color.
     * It is equivalent to subtracting each color component from 255.
     */
    void invertColor();



    /**
     * @brief Scales the red component by a given coefficient.
     * 
     * Multiplies the red component by the given coefficient, clamping the result within the valid range [0, 255].
     * 
     * @param coefficient The factor by which the red component is scaled.
     */
    void scaleRed(const double coefficient);


    /**
     * @brief Scales the green component by a given coefficient.
     * 
     * Multiplies the green component by the given coefficient, clamping the result within the valid range [0, 255].
     * 
     * @param coefficient The factor by which the green component is scaled.
     */
    void scaleGreen(const double coefficient);


    /**
     * @brief Scales the blue component by a given coefficient.
     * 
     * Multiplies the blue component by the given coefficient, clamping the result within the valid range [0, 255].
     * 
     * @param coefficient The factor by which the blue component is scaled.
     */
    void scaleBlue(const double coefficient);


    /**
     * @brief Adjusts the brightness of the color by scaling all components.
     * 
     * Multiplies the red, green, and blue components by the given coefficient, effectively making the color brighter (>1.0) or darker (<1.0).
     * The result is clamped within the valid range [0, 255] to prevent overflow.
     * 
     * @param coefficient The brightness scaling factor (e.g., 1.2 increases brightness, 0.8 decreases it).
     */
    void scaleColor(const double coefficient);


    /**
     * @brief Adjusts the red component by a given increment.
     * 
     * Adds the given increment to the red component, clamping the result within the valid range [0, 255].
     * 
     * @param increment The value to be added to the red component.
     */
    void adjustRed(const double increment);


    /**
     * @brief Adjusts the green component by a given increment.
     * 
     * Adds the given increment to the green component, clamping the result within the valid range [0, 255].
     * 
     * @param increment The value to be added to the green component.
     */
    void adjustGreen(const double increment);


    /**
     * @brief Adjusts the blue component by a given increment.
     * 
     * Adds the given increment to the blue component, clamping the result within the valid range [0, 255].
     * 
     * @param increment The value to be added to the blue component.
     */
    void adjustBlue(const double increment);

    /**
     * @brief Adjusts the brightness of the color by modifying all components.  
     *  
     * Increases or decreases the red, green, and blue components by the given increment, effectively making the color brighter (positive values) or darker (negative values).  
     * The result is clamped within the valid range [0, 255] to prevent overflow.  
     *  
     * @param increment The value to be added to all components (e.g., +20 brightens the color, -20 darkens it).  
     */
    void adjustColor(const double increment);


    /**
     * @brief Converts the color to grayscale.
     * 
     * This sets the red, green, and blue components to their average value,
     * creating a neutral tone while maintaining brightness.
     */
    void convertToGrayscale();


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
