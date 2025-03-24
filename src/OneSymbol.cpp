#include "OneSymbol.h"

OneSymbol::OneSymbol()
    : symbol(u' '), foregroundColor(Colors::BLACK), backgroundColor(Colors::WHITE) {};


OneSymbol::OneSymbol(const char Symbol, const Color & ForegroundColor, const Color & BackgroundColor)
    : symbol(Symbol), foregroundColor(ForegroundColor), backgroundColor(BackgroundColor) {};


OneSymbol::OneSymbol(const Color & ForegroundColor, const Color & BackgroundColor)
    : symbol(u' '), foregroundColor(ForegroundColor), backgroundColor(BackgroundColor) {}


void OneSymbol::invertColor()
{
    backgroundColor.invertColor();
    foregroundColor.invertColor();

    return;
}


std::ostream & operator<<(std::ostream &os, const OneSymbol & oneSymbol)
{
    const auto & [symbol,foregroundColor,backgroundColor] = oneSymbol;
    os  << "\033[38;2;"
        << foregroundColor.getRed() << ";" << foregroundColor.getGreen() << ";" << foregroundColor.getBlue() << "m"
        << "\033[48;2;"
        << backgroundColor.getRed() << ";" << backgroundColor.getGreen() << ";" << backgroundColor.getBlue() << "m"
        << symbol
        << "\033[0m";

    return os;
}


std::string OneSymbol::toString() const
{
    return
        "\033[38;2;"
        + std::to_string(foregroundColor.getRed()) + ";" + std::to_string(foregroundColor.getGreen()) + ";" + std::to_string(foregroundColor.getBlue()) + "m"
        + "\033[48;2;"
        + std::to_string(backgroundColor.getRed()) + ";" + std::to_string(backgroundColor.getGreen()) + ";" +std::to_string(backgroundColor.getBlue()) + "m"
        + symbol
        + "\033[0m";
}
