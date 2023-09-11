add_subdirectory(ResourceVerifier)
add_subdirectory(WindowsApiWrapper)

add_executable(SpotifyAddBlocker main.cpp)

target_link_libraries(SpotifyAddBlocker ResourceVerifier)
