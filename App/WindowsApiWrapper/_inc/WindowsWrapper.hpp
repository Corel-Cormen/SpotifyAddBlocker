#ifndef WINDOWSWRAPPER_HPP
#define WINDOWSWRAPPER_HPP

#include <windows.h>

class WindowsWrapper
{
public:
    virtual DWORD WINAPI getFileAttributesA(LPCSTR filePath);
};

#endif // WINDOWSWRAPPER_HPP