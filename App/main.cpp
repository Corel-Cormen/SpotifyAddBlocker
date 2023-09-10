#include <iostream>
#include "WinResourceVerifer.hpp"

int main()
{
    WinResourceVerifer verifier;
    auto result = verifier.checkResourceAvailability();
    std::cout << "Verifier file = " << result << std::endl;
}
