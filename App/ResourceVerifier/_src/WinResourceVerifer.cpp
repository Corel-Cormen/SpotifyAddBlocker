#include "WinResourceVerifer.hpp"
#include "fmt/printf.h"

WinResourceVerifer::WinResourceVerifer(WindowsWrapper& _windowsWrapper) :
    windowsWrapper(_windowsWrapper)
{

}

Error_Code_T WinResourceVerifer::checkResourceAvailability()
{
    Error_Code_T result;
    const char* resourcePath = ".\\Resource";

    DWORD dwAttrib = windowsWrapper.getFileAttributesA(resourcePath); 

    if(dwAttrib != INVALID_FILE_ATTRIBUTES)
    {
        if(dwAttrib & FILE_ATTRIBUTE_DIRECTORY)
        {
            fmt::printf("Find Resource Success\n");
            result = Error_Code_T::SUCCESS;
        }
        else
        {
            fmt::printf("File is not directory\n");
            result = Error_Code_T::FLAW;
        }
    }
    else
    {
        fmt::printf("Invalid search directory\n");
        result = Error_Code_T::NOEXIST;
    }

    return result;
}
