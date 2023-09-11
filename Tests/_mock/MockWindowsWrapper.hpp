#ifndef MOCKWINDOWSWRAPPER_HPP
#define MOCKWINDOWSWRAPPER_HPP

#include "gmock/gmock.h"
#include "WindowsWrapper.hpp"

class MockWindowsWrapper : public WindowsWrapper
{
public:
    MOCK_METHOD(DWORD WINAPI, getFileAttributesW, (LPCWSTR filePath), (override));
};

#endif // MOCKWINDOWSWRAPPER_HPP
