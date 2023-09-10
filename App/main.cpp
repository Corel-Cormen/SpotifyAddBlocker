#include <iostream>
#include "WinResourceVerifer.hpp"
#include "WindowsWrapper.hpp"

int main()
{
    WindowsWrapper windowsWrapper;
    WinResourceVerifer verifier(windowsWrapper);
    auto result = verifier.checkResourceAvailability();
    std::cout << "Verifier file = " << result << std::endl;
}
