#include "WindowsWrapper.hpp"

DWORD WINAPI WindowsWrapper::getFileAttributesW(LPCWSTR filePath)
{
    return GetFileAttributesW(filePath);
}
