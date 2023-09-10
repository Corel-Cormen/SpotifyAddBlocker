cmake_minimum_required(VERSION 3.10)

project(SpotifyAddBlocker)

set(FMT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/fmt/include)
set(FMT_LIBRARY ${CMAKE_SOURCE_DIR}/3rdparty/fmt/libfmt.a)

set(GTEST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/googletest/include)
set(GTEST_LIBRARY ${CMAKE_SOURCE_DIR}/3rdparty/googletest/libgtest.a)
set(GMOCK_LIBRARY ${CMAKE_SOURCE_DIR}/3rdparty/googletest/libgmock.a)

set(COMMON_TOOLS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/App/CommonTools/_inc)

add_subdirectory(App)
add_subdirectory(Tests)
