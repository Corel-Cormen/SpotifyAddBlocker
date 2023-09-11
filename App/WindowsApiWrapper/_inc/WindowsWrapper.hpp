#ifndef WINDOWSWRAPPER_HPP
#define WINDOWSWRAPPER_HPP

#include <windows.h>

class WindowsWrapper
{
public:
    virtual DWORD WINAPI getFileAttributesW(LPCWSTR filePath);
};

#endif // WINDOWSWRAPPER_HPP
