add_subdirectory(ResourceVerifier)

add_executable(SpotifyAddBlocker main.cpp)

target_link_libraries(SpotifyAddBlocker ResourceVerifier ${FMT_LIBRARY})
