#include <iostream>
#include <thread>

#include "GrayScaleGradient.h"

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);   
    GrayScaleGradient object(60);
    object.run();
    
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    return 0;
}
