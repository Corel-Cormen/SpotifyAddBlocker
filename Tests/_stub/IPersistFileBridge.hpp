#include <windows.h>
#include <objidl.h>

struct IPersistFileBridge : public IPersistFile
{
public: 
    virtual HRESULT QueryInterface(const IID& iid, PVOID* ppvObject) override;

    virtual HRESULT Load(LPCOLESTR pszFileName, DWORD dwMode) override;

    virtual ULONG AddRef() override;

    virtual ULONG Release() override;

    virtual HRESULT GetClassID(CLSID* pClassID) override;

    virtual HRESULT IsDirty() override;

	virtual HRESULT Save(LPCOLESTR pszFileName, BOOL fRemember) override;

    virtual HRESULT SaveCompleted(LPCOLESTR pszFileName) override;

    virtual HRESULT GetCurFile(LPOLESTR* ppszFileName) override;

public:
    HRESULT result_Load;
};

HRESULT IPersistFileBridge::QueryInterface(const IID& iid, PVOID* ppvObject)
{
    __UNUSED_PARAM(iid);
    __UNUSED_PARAM(ppvObject);

    return static_cast<HRESULT>(true);
}

HRESULT IPersistFileBridge::Load(LPCOLESTR pszFileName, DWORD dwMode)
{
    __UNUSED_PARAM(pszFileName);
    __UNUSED_PARAM(dwMode);

    return result_Load;
}

ULONG IPersistFileBridge::AddRef()
{
    return static_cast<ULONG>(true);
}

ULONG IPersistFileBridge::Release()
{
    return static_cast<ULONG>(true);
}

HRESULT IPersistFileBridge::GetClassID(CLSID* pClassID)
{
    __UNUSED_PARAM(pClassID);

    return static_cast<HRESULT>(true);
}

HRESULT IPersistFileBridge::IsDirty()
{
    return static_cast<HRESULT>(true);
}

HRESULT IPersistFileBridge::Save(LPCOLESTR pszFileName, BOOL fRemember)
{
    __UNUSED_PARAM(pszFileName);
    __UNUSED_PARAM(fRemember);

    return static_cast<HRESULT>(true);
}

HRESULT IPersistFileBridge::SaveCompleted(LPCOLESTR pszFileName)
{
    __UNUSED_PARAM(pszFileName);

    return static_cast<HRESULT>(true);
}

HRESULT IPersistFileBridge::GetCurFile(LPOLESTR* pszFileName)
{
    __UNUSED_PARAM(pszFileName);

    return static_cast<HRESULT>(true);
}
