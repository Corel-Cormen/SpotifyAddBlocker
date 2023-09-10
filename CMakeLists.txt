cmake_minimum_required(VERSION 3.10)

project(SpotifyAddBlocker)

set(FMT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/fmt/include)
set(FMT_LIBRARY ${CMAKE_SOURCE_DIR}/3rdparty/fmt/libfmt.a)

set(COMMON_TOOLS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/CommonTools/_inc)

add_subdirectory(ResourceVerifier)

add_executable(SpotifyAddBlocker main.cpp)

target_link_libraries(SpotifyAddBlocker ResourceVerifier ${FMT_LIBRARY})
