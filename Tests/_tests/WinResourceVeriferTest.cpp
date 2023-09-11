#include <gtest/gtest.h>
#include "WinResourceVerifer.hpp"
#include "MockComObjBaseWrapper.hpp"
#include "MockWindowsWrapper.hpp"
#include "IPersistFileBridge.hpp"
#include "IShellLinkWBridge.hpp"

using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::DoAll;

class WinResourceVeriferTest : public ::testing::Test
{
public:
    WinResourceVeriferTest() :
        winResourceVerifer(mockWindowsWrapper, mockComObjBaseWrapper)
    {

    }

protected:
    WinResourceVerifer winResourceVerifer;
    MockComObjBaseWrapper mockComObjBaseWrapper;
    MockWindowsWrapper mockWindowsWrapper;
};

TEST_F(WinResourceVeriferTest, checkResourceAvailabilityFunctionTest)
{
    EXPECT_CALL(mockWindowsWrapper, getFileAttributesW).Times(1).WillOnce(Return(INVALID_FILE_ATTRIBUTES));
    EXPECT_EQ(Error_Code_T::NOEXIST, winResourceVerifer.checkResourceAvailability());

    EXPECT_CALL(mockWindowsWrapper, getFileAttributesW).Times(1).WillOnce(Return(0));
    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceAvailability());

    EXPECT_CALL(mockWindowsWrapper, getFileAttributesW).Times(1).WillOnce(Return(FILE_ATTRIBUTE_DIRECTORY));
    EXPECT_EQ(Error_Code_T::SUCCESS, winResourceVerifer.checkResourceAvailability());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityCOMInitFail)
{
    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(-1));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).Times(0);

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityCOMCreateInstanceStatusFail)
{
    IShellLinkWBridge iShellLinkWBridge;

    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(&iShellLinkWBridge), Return(-1)));

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityCOMCreateInstanceIsNullptr)
{
    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(nullptr), Return(0)));

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityQueryInterfaceStatusFail)
{
    IPersistFileBridge iPersistFile;
    IShellLinkWBridge iShellLinkWBridge;
    iShellLinkWBridge.ppvObject_QueryInterface = &iPersistFile;
    iShellLinkWBridge.result_QueryInterface = -1;

    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(&iShellLinkWBridge), Return(0)));

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityQueryInterfaceIsNullptr)
{
    IShellLinkWBridge iShellLinkWBridge;
    iShellLinkWBridge.ppvObject_QueryInterface = nullptr;
    iShellLinkWBridge.result_QueryInterface = 0;

    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(&iShellLinkWBridge), Return(0)));

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityLoadResourceStatusFail)
{
    IPersistFileBridge iPersistFile;
    iPersistFile.result_Load = -1;
    IShellLinkWBridge iShellLinkWBridge;
    iShellLinkWBridge.ppvObject_QueryInterface = &iPersistFile;
    iShellLinkWBridge.result_QueryInterface = 0;

    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(&iShellLinkWBridge), Return(0)));

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityGetPathStatusFail)
{
    IPersistFileBridge iPersistFile;
    iPersistFile.result_Load = 0;
    IShellLinkWBridge iShellLinkWBridge;
    iShellLinkWBridge.ppvObject_QueryInterface = &iPersistFile;
    iShellLinkWBridge.result_QueryInterface = 0;
    (void) wcscpy(iShellLinkWBridge.pszFile_GetPath, L"Spotify.exe");
    iShellLinkWBridge.result_GetPath = -1;

    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(&iShellLinkWBridge), Return(0)));

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityGetPathIsEmpty)
{
    IPersistFileBridge iPersistFile;
    iPersistFile.result_Load = 0;
    IShellLinkWBridge iShellLinkWBridge;
    iShellLinkWBridge.ppvObject_QueryInterface = &iPersistFile;
    iShellLinkWBridge.result_QueryInterface = 0;
    (void) wcscpy(iShellLinkWBridge.pszFile_GetPath, L"");
    iShellLinkWBridge.result_GetPath = 0;

    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(&iShellLinkWBridge), Return(0)));

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegrityGetPathNotContainExeStr)
{
    IPersistFileBridge iPersistFile;
    iPersistFile.result_Load = 0;
    IShellLinkWBridge iShellLinkWBridge;
    iShellLinkWBridge.ppvObject_QueryInterface = &iPersistFile;
    iShellLinkWBridge.result_QueryInterface = 0;
    (void) wcscpy(iShellLinkWBridge.pszFile_GetPath, L"123");
    iShellLinkWBridge.result_GetPath = 0;

    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(&iShellLinkWBridge), Return(0)));

    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceIntegrity());
}

TEST_F(WinResourceVeriferTest, checkResourceIntegritySuccessFindPath)
{
    IPersistFileBridge iPersistFile;
    iPersistFile.result_Load = 0;
    IShellLinkWBridge iShellLinkWBridge;
    iShellLinkWBridge.ppvObject_QueryInterface = &iPersistFile;
    iShellLinkWBridge.result_QueryInterface = 0;
    (void) wcscpy(iShellLinkWBridge.pszFile_GetPath, L"Spotify.exe");
    iShellLinkWBridge.result_GetPath = 0;

    EXPECT_CALL(mockComObjBaseWrapper, coInitialize).Times(1).WillOnce(Return(0));
    EXPECT_CALL(mockComObjBaseWrapper, coUninitialize).Times(1);
    EXPECT_CALL(mockComObjBaseWrapper, coCreateInstance).WillOnce(DoAll(SetArgPointee<4>(&iShellLinkWBridge), Return(0)));

    EXPECT_EQ(Error_Code_T::SUCCESS, winResourceVerifer.checkResourceIntegrity());
}
