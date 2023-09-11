#ifndef OBJBASEWRAPPER_HPP
#define OBJBASEWRAPPER_HPP

#include <ShlObj.h>

class ComObjBaseWrapper
{
public:
    virtual HRESULT WINAPI coInitialize(PVOID pvReserved);

    virtual void WINAPI coUninitialize();

    virtual HRESULT WINAPI coCreateInstance(const CLSID& rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, const IID& riid, PVOID* ppv);
};

#endif // OBJBASEWRAPPER_HPP