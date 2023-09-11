#include "ComObjBaseWrapper.hpp"

HRESULT WINAPI ComObjBaseWrapper::coInitialize(PVOID pvReserved)
{
    return CoInitialize(pvReserved);
}

void WINAPI ComObjBaseWrapper::coUninitialize()
{
    CoUninitialize();
}

HRESULT WINAPI ComObjBaseWrapper::coCreateInstance(const CLSID& rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, const IID& riid, PVOID* ppv)
{
    return CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
}
