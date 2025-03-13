#include <iostream>


#include "TerminalControl.h"
#include "OneSymbol.h"
#include "TerminalEffects.h"

int main(void)
{
    //OneSymbol test('#', Colors::RED, Colors::GREEN);
    //std::cout << test << test;
    //std::cout << test.foregroundColor.getBlue() << std::endl;
    
    //TerminalControl test;
    //test.getTerminalSize();
    //test.setTerminalSize();
    //test.printTerminal();
    //char a;
    //std::cin >> a;
    //test.clearTerminal();
    //TerminalEffects::changeColorEffect(test, Colors::BLUE);
    //test.printTerminal();
    //std::cin >> a;
    //test.clearTerminal();
    


    TerminalControl test;
    test.getTerminalSize();
    test.setTerminalSize();
    test.printTerminal();
    char a;
    std::cin >> a;
    test.clearTerminal();
    TerminalEffects::invertColorEffect(test);
    test.printTerminal();
    std::cin >> a;
    test.clearTerminal();
    return 0;
}
