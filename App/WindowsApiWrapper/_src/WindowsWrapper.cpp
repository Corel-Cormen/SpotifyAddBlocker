#include "WindowsWrapper.hpp"

DWORD WINAPI WindowsWrapper::getFileAttributesA(LPCSTR filePath)
{
    return GetFileAttributesA(filePath);
}
