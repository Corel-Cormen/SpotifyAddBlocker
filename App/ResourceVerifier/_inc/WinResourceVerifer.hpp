#ifndef WINRESOURCEVERIFIER_HPP
#define WINRESOURCEVERIFIER_HPP

#include "ResourceVerifierInterface.hpp"
#include "WindowsWrapper.hpp"
#include "ComObjBaseWrapper.hpp"

class WinResourceVerifer : public ResourceVerifierInterface
{
public:
    explicit WinResourceVerifer(WindowsWrapper& _windowsWrapper, ComObjBaseWrapper& _objBaseWrapper);

    virtual ~WinResourceVerifer() {}

    virtual Error_Code_T checkResourceAvailability() override;

    virtual Error_Code_T checkResourceIntegrity() override;

private:
    WindowsWrapper& windowsWrapper;
    ComObjBaseWrapper& comObjBaseWrapper;
};

#endif // WINRESOURCEVERIFIER_HPP
