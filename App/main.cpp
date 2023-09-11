#include <iostream>
#include "WinResourceVerifer.hpp"
#include "WindowsWrapper.hpp"
#include "ComObjBaseWrapper.hpp"

int main()
{
    WindowsWrapper windowsWrapper;
    ComObjBaseWrapper comObjBaseWrapper;
    WinResourceVerifer verifier(windowsWrapper, comObjBaseWrapper);
    auto result = verifier.checkResourceAvailability();
    std::cout << "Verifier file = " << result << std::endl;

    verifier.checkResourceIntegrity();
}
