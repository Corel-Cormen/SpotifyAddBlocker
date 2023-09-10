#ifndef WINRESOURCEVERIFIER_HPP
#define WINRESOURCEVERIFIER_HPP

#include "ResourceVerifierInterface.hpp"

class WinResourceVerifer : public ResourceVerifierInterface
{
public:
    WinResourceVerifer();

    virtual ~WinResourceVerifer() {}

    virtual Error_Code_T checkResourceAvailability() override;
};

#endif // WINRESOURCEVERIFIER_HPP