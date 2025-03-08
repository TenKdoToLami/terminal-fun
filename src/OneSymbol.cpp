#include "OneSymbol.h"


OneSymbol::OneSymbol(const char Symbol, const Color & ForegroundColor, const Color & BackgroundColor)
    : symbol(Symbol), foregroundColor(ForegroundColor), backgroundColor(BackgroundColor) {};


OneSymbol::OneSymbol(const Color & ForegroundColor, const Color & BackgroundColor)
    : symbol(u' '), foregroundColor(ForegroundColor), backgroundColor(BackgroundColor) {}


std::ostream &operator<<(std::ostream &os, const OneSymbol & oneSymbol)
{
    const auto & [symbol,foregroundColor,backgroundColor] = oneSymbol;
    os  << "\033[38;2;"
        << foregroundColor.red << ";" << foregroundColor.green << ";" << foregroundColor.blue << "m"
        << "\033[48;2;"
        << backgroundColor.red << ";" << backgroundColor.green << ";" << backgroundColor.blue << "m"
        << symbol
        << "\033[0m";
        
       return os;
}
