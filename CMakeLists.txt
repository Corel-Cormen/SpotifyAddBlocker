cmake_minimum_required(VERSION 3.10)

project(SpotifyAddBlocker)

set(CMAKE_CXX_STANDARD 17)

set(FMT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/fmt/include)
set(FMT_LIBRARY ${CMAKE_SOURCE_DIR}/3rdparty/fmt/libfmt.a)

set(COMMON_TOOLS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/App/CommonTools/_inc)

add_subdirectory(App)
add_subdirectory(Tests)
