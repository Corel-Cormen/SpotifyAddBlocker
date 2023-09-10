#ifndef WINRESOURCEVERIFIER_HPP
#define WINRESOURCEVERIFIER_HPP

#include "ResourceVerifierInterface.hpp"
#include "WindowsWrapper.hpp"

class WinResourceVerifer : public ResourceVerifierInterface
{
public:
    WinResourceVerifer(WindowsWrapper& _windowsWrapper);

    virtual ~WinResourceVerifer() {}

    virtual Error_Code_T checkResourceAvailability() override;

private:
    WindowsWrapper& windowsWrapper;
};

#endif // WINRESOURCEVERIFIER_HPP