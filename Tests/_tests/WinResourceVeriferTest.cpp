#include <gtest/gtest.h>
#include "WinResourceVerifer.hpp"
#include "MockWindowsWrapper.hpp"

using ::testing::Return;

class WinResourceVeriferTest : public ::testing::Test
{
public:
    WinResourceVeriferTest() :
        winResourceVerifer(mockWindowsWrapper)
    {

    }

protected:
    WinResourceVerifer winResourceVerifer;
    MockWindowsWrapper mockWindowsWrapper;
};

TEST_F(WinResourceVeriferTest, checkResourceAvailabilityFunctionTest)
{
    EXPECT_CALL(mockWindowsWrapper, getFileAttributesA).Times(1).WillOnce(Return(INVALID_FILE_ATTRIBUTES));
    EXPECT_EQ(Error_Code_T::NOEXIST, winResourceVerifer.checkResourceAvailability());

    EXPECT_CALL(mockWindowsWrapper, getFileAttributesA).Times(1).WillOnce(Return(0));
    EXPECT_EQ(Error_Code_T::FLAW, winResourceVerifer.checkResourceAvailability());

    EXPECT_CALL(mockWindowsWrapper, getFileAttributesA).Times(1).WillOnce(Return(FILE_ATTRIBUTE_DIRECTORY));
    EXPECT_EQ(Error_Code_T::SUCCESS, winResourceVerifer.checkResourceAvailability());
}
