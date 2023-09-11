#ifndef ISHELLLINKWBRIDGE_HPP
#define ISHELLLINKWBRIDGE_HPP

#include <windows.h>
#include <shlobj.h>

#include <memory>

struct IShellLinkWBridge : public IShellLinkW
{
public:
    virtual HRESULT QueryInterface(const IID& iid, PVOID* ppvObject) override;

    virtual ULONG AddRef() override;

    virtual ULONG Release() override;

    virtual HRESULT GetPath(LPWSTR pszFile, int cch, WIN32_FIND_DATAW* pfd, DWORD fFlags) override;

    virtual HRESULT GetIDList(LPITEMIDLIST* ppidl) override;

	virtual HRESULT SetIDList(LPCITEMIDLIST pidl) override;

    virtual HRESULT GetDescription(LPWSTR pszName, int cch) override;

    virtual HRESULT SetDescription(LPCWSTR pszName) override;

    virtual HRESULT GetWorkingDirectory(LPWSTR pszDir, int cch) override;

    virtual HRESULT SetWorkingDirectory(LPCWSTR pszDir) override;

    virtual HRESULT GetArguments(LPWSTR pszDir, int cch) override;

    virtual HRESULT SetArguments(LPCWSTR pszDir) override;

    virtual HRESULT GetHotkey(PWORD pwHotkey) override;

    virtual HRESULT SetHotkey(WORD wHotkey) override;

    virtual HRESULT GetShowCmd(int* piShowCmd) override;

    virtual HRESULT SetShowCmd(int iShowCmd) override;

	virtual HRESULT GetIconLocation(LPWSTR pszIconPath, int cch, int* piIcon) override;

    virtual HRESULT SetIconLocation(LPCWSTR pszIconPath, int iIcon) override;

    virtual HRESULT SetRelativePath(LPCWSTR pszPathRel, DWORD dwReserved) override;

    virtual HRESULT Resolve(HWND hwnd, DWORD fFlags) override;

    virtual HRESULT SetPath(LPCWSTR pszFile) override;

public:
    IPersistFileBridge* ppvObject_QueryInterface;
    HRESULT result_QueryInterface;

    wchar_t pszFile_GetPath[MAX_PATH];
    HRESULT result_GetPath;
};

HRESULT IShellLinkWBridge::QueryInterface(const IID& iid, PVOID* ppvObject)
{
    __UNUSED_PARAM(iid);

    *ppvObject = reinterpret_cast<PVOID*>(ppvObject_QueryInterface);

    return result_QueryInterface;
}

ULONG IShellLinkWBridge::AddRef()
{
    return static_cast<ULONG>(true);
}

ULONG IShellLinkWBridge::Release()
{
    return static_cast<ULONG>(true);
}

HRESULT IShellLinkWBridge::GetPath(LPWSTR pszFile, int cch, WIN32_FIND_DATAW* pfd, DWORD fFlags)
{
    __UNUSED_PARAM(cch);
    __UNUSED_PARAM(pfd);
    __UNUSED_PARAM(fFlags);

    (void) wcscpy(pszFile, pszFile_GetPath);

    return result_GetPath;
}

HRESULT IShellLinkWBridge::GetIDList(LPITEMIDLIST* ppidl)
{
    __UNUSED_PARAM(ppidl);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetIDList(LPCITEMIDLIST pidl)
{
    __UNUSED_PARAM(pidl);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::GetDescription(LPWSTR pszName, int cch)
{
    __UNUSED_PARAM(pszName);
    __UNUSED_PARAM(cch);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetDescription(LPCWSTR pszName)
{
    __UNUSED_PARAM(pszName);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::GetWorkingDirectory(LPWSTR pszDir, int cch)
{
    __UNUSED_PARAM(pszDir);
    __UNUSED_PARAM(cch);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetWorkingDirectory(LPCWSTR pszDir)
{
    __UNUSED_PARAM(pszDir);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::GetArguments(LPWSTR pszDir, int cch)
{
    __UNUSED_PARAM(pszDir);
    __UNUSED_PARAM(cch);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetArguments(LPCWSTR pszDir)
{
    __UNUSED_PARAM(pszDir);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::GetHotkey(PWORD pwHotkey)
{
    __UNUSED_PARAM(pwHotkey);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetHotkey(WORD wHotkey)
{
    __UNUSED_PARAM(wHotkey);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::GetShowCmd(int* piShowCmd)
{
    __UNUSED_PARAM(piShowCmd);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetShowCmd(int iShowCmd)
{
    __UNUSED_PARAM(iShowCmd);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::GetIconLocation(LPWSTR pszIconPath, int cch, int* piIcon)
{
    __UNUSED_PARAM(pszIconPath);
    __UNUSED_PARAM(cch);
    __UNUSED_PARAM(piIcon);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetIconLocation(LPCWSTR pszIconPath, int iIcon)
{
    __UNUSED_PARAM(pszIconPath);
    __UNUSED_PARAM(iIcon);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetRelativePath(LPCWSTR pszPathRel, DWORD dwReserved)
{
    __UNUSED_PARAM(pszPathRel);
    __UNUSED_PARAM(dwReserved);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::Resolve(HWND hwnd, DWORD fFlags)
{
    __UNUSED_PARAM(hwnd);
    __UNUSED_PARAM(fFlags);

    return static_cast<HRESULT>(true);
}

HRESULT IShellLinkWBridge::SetPath(LPCWSTR pszFile)
{
    __UNUSED_PARAM(pszFile);

    return static_cast<HRESULT>(true);
}

#endif // ISHELLLINKWBRIDGE_HPP