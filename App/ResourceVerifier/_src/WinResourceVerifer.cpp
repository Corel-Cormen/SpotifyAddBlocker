#include "WinResourceVerifer.hpp"
#include "fmt/printf.h"
#include "fmt/xchar.h"

WinResourceVerifer::WinResourceVerifer(WindowsWrapper& _windowsWrapper, 
                                        ComObjBaseWrapper& _comObjBaseWrapper) :
    windowsWrapper(_windowsWrapper),
    comObjBaseWrapper(_comObjBaseWrapper)
{

}

Error_Code_T WinResourceVerifer::checkResourceAvailability()
{
    Error_Code_T result;
    const LPCOLESTR resourcePath = L".\\Resource";

    DWORD dwAttrib = windowsWrapper.getFileAttributesW(resourcePath);

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

Error_Code_T WinResourceVerifer::checkResourceIntegrity()
{
    Error_Code_T result = Error_Code_T::FLAW;

    HRESULT hr = comObjBaseWrapper.coInitialize(NULL);
    if(SUCCEEDED(hr))
    {
        IShellLinkW* pShellLink = nullptr;
        hr = comObjBaseWrapper.coCreateInstance(CLSID_ShellLink,
                                                nullptr,
                                                CLSCTX_INPROC_SERVER,
                                                IID_IShellLinkW,
                                                reinterpret_cast<LPVOID*>(&pShellLink));

        if(SUCCEEDED(hr) && (pShellLink != nullptr))
        {
            IPersistFile* pPersistFile = nullptr;
            hr = pShellLink->QueryInterface(IID_IPersistFile, reinterpret_cast<PVOID*>(&pPersistFile));

            if(SUCCEEDED(hr) && (pPersistFile != nullptr))
            {
                LPCOLESTR resourcePath = L".\\Resource\\Spotify.exe.lnk";
                hr = pPersistFile->Load(resourcePath, STGM_READ);

                if(SUCCEEDED(hr))
                {
                    wchar_t filePath[MAX_PATH];
                    hr = pShellLink->GetPath(filePath, MAX_PATH, nullptr, SLGP_RAWPATH);

                    if(SUCCEEDED(hr))
                    {
                        if(wcsstr(filePath, L"Spotify.exe") != nullptr)
                        {
                            fmt::print(L"Find orginal path file: '{}'\n", filePath);
                            result = Error_Code_T::SUCCESS;
                        }
                        else
                        {
                            fmt::printf("File is not link to .exe file\n");
                        }
                    }
                    else
                    {
                        fmt::printf("Error get file path\n");
                    }
                }
                else
                {
                    fmt::print(L"Load file: '{}' properties fail\n", resourcePath);
                }

                (void) pPersistFile->Release();
            }
            else
            {
                fmt::printf("Queries to COM interface identifying fail\n");
            }

            (void) pShellLink->Release();
        }
        else
        {
            fmt::printf("Initialize CLSID fail\n");
        }
    }
    else
    {
        fmt:printf("Initialize COM in current thread error\n");
    }

    comObjBaseWrapper.coUninitialize();

    return result;
}
