#ifndef MOCKCOMOBJBASEWRAPPER_HPP
#define MOCKCOMOBJBASEWRAPPER_HPP

#include "gmock/gmock.h"
#include "ComObjBaseWrapper.hpp"

class MockComObjBaseWrapper : public ComObjBaseWrapper
{
public:
    MOCK_METHOD(HRESULT WINAPI, coInitialize, (PVOID pvReserved), (override));
    MOCK_METHOD(void WINAPI, coUninitialize, (), (override));
    MOCK_METHOD(HRESULT WINAPI, coCreateInstance, (const CLSID& rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, const IID& riid, PVOID* ppv), (override));
};

#endif