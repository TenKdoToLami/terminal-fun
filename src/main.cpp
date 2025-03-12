#include <iostream>


#include "TerminalControl.h"
#include "OneSymbol.h"


int main(void)
{
    OneSymbol test('#', Colors::RED, Colors::GREEN);
    std::cout << test << test;
    std::cout << test.foregroundColor.getBlue() << std::endl;
    return 0;
}
