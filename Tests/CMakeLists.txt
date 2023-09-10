add_executable(SpotifyAddBlockerTest main.cpp
                                    test.cpp)

target_link_libraries(SpotifyAddBlockerTest ${GTEST_LIBRARY} ${GMOCK_LIBRARY})

target_include_directories(SpotifyAddBlockerTest PUBLIC ${GTEST_INCLUDE_DIR})
