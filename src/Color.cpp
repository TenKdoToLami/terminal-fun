#include "Color.h"


int Color::getRed() const
{
    return std::clamp(int(red), 0, 255);
}


int Color::getBlue() const
{
    return std::clamp(int(blue), 0, 255);
}


int Color::getGreen() const
{
    return std::clamp(int(green), 0, 255);
}


void Color::setColor(const Color newColor)
{
    red = newColor.getRed();
    green = newColor.getGreen();
    blue = newColor.getBlue();

    return;
}


void Color::setColor(const double Red, const double Green, const double Blue)
{
    red = std::clamp(Red, 0.0, 255.0);
    blue = std::clamp(Blue, 0.0, 255.0);
    green = std::clamp(Green, 0.0, 255.0);

    return;
}


void Color::setRed(const double value)
{
    red = std::clamp(value, 0.0, 255.0);

    return;
}


void Color::setGreen(const double value)
{
    green = std::clamp(value, 0.0, 255.0);

    return;
}


void Color::setBlue(const double value)
{
    blue = std::clamp(value, 0.0, 255.0);

    return;
}


void Color::invertRed()
{
    red = std::max(0.0,255.0 - red);

    return;
}


void Color::invertGreen()
{
    green = std::max(0.0, 255.0 - green);

    return;
}


void Color::invertBlue()
{
    blue = std::max(0.0, 255.0 - blue);

    return;
}


void Color::invertColor()
{ 
    invertRed();
    invertGreen();
    invertBlue(); 

    return;
}


void Color::scaleRed(const double coefficient) 
{
    red = std::clamp(red * coefficient, 0.0, 255.0);

    return;
}


void Color::scaleGreen(const double coefficient) 
{
    green = std::clamp(green * coefficient, 0.0, 255.0);

    return;
}


void Color::scaleBlue(const double coefficient) 
{
    blue = std::clamp(blue * coefficient, 0.0, 255.0);

    return;
}


void Color::scaleColor(const double coefficient) 
{
    scaleRed(coefficient);
    scaleGreen(coefficient);
    scaleBlue(coefficient);

    return;
}


namespace Colors
{
    const Color RED(255, 0, 0);
    const Color DARK_RED(139, 0, 0);
    const Color CORAL(255, 127, 80);
    const Color PINK(255, 192, 203);

    const Color GREEN(0, 255, 0);
    const Color LIME(0, 255, 0);
    const Color DARK_GREEN(0, 100, 0);
    const Color LIGHT_GREEN(144, 238, 144);
    const Color FOREST_GREEN(34, 139, 34);
    const Color MEDIUM_SEA_GREEN(60, 179, 113);

    const Color BLUE(0, 0, 255);
    const Color DARK_BLUE(0, 0, 139);
    const Color LIGHT_BLUE(173, 216, 230);
    const Color TURQUOISE(64, 224, 208);
    const Color AQUA(0, 255, 255);
    const Color TEAL(0, 128, 128);
    const Color SLATEGRAY(112, 128, 144);

    const Color YELLOW(255, 255, 0);
    const Color GOLD(255, 215, 0);
    const Color LIGHT_YELLOW(255, 255, 224);
    const Color IVORY(255, 255, 240);
    const Color BEIGE(245, 245, 220);

    const Color CYAN(0, 255, 255);
    const Color DARK_CYAN(0, 139, 139);

    const Color ORANGE(255, 165, 0);
    const Color DARK_ORANGE(255, 140, 0);
    const Color SADDLE_BROWN(139, 69, 19);
    const Color CHOCOLATE(210, 105, 30);

    const Color PURPLE(128, 0, 128);
    const Color INDIGO(75, 0, 130);
    const Color DARK_VIOLET(148, 0, 211);
    const Color VIOLET(238, 130, 238);
    const Color FUCHSIA(255, 0, 255);

    const Color BROWN(165, 42, 42);
    const Color TAN(210, 180, 140);
    const Color SILVER(192, 192, 192);
    const Color GRAY(169, 169, 169);
    const Color LIGHT_GRAY(211, 211, 211);
    const Color DARK_GRAY(169, 169, 169);

    const Color BLACK(0, 0, 0);
    const Color WHITE(255, 255, 255);

    const Color SNOW(255, 250, 250);
    const Color SEASHELL(255, 245, 238);
    const Color OLIVE(128, 128, 0);
}