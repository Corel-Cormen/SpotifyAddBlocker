#ifndef RESOURCEVERIFIERINTERFACE_HPP
#define RESOURCEVERIFIERINTERFACE_HPP

#include "CommonTypes.hpp"

class ResourceVerifierInterface
{
public:
    ResourceVerifierInterface() = default;

    virtual ~ResourceVerifierInterface() {}

    virtual Error_Code_T checkResourceAvailability() = 0;

    virtual Error_Code_T checkResourceIntegrity() = 0;
};

#endif // RESOURCEVERIFIERINTERFACE_HPP
