set(GTEST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/googletest/include)
set(GTEST_LIBRARY ${CMAKE_SOURCE_DIR}/3rdparty/googletest/libgtest.a)
set(GMOCK_LIBRARY ${CMAKE_SOURCE_DIR}/3rdparty/googletest/libgmock.a)
set(GTEST_MAIN ${CMAKE_SOURCE_DIR}/3rdparty/googletest/libgtest_main.a)

set(SOURCES _tests/WinResourceVeriferTest.cpp)

add_executable(SpotifyAddBlockerTest ${SOURCES})

target_link_libraries(SpotifyAddBlockerTest ${GTEST_LIBRARY}
                                            ${GMOCK_LIBRARY}
                                            ${GTEST_MAIN}
                                            ${FMT_LIBRARY}
                                            ResourceVerifier)

target_include_directories(SpotifyAddBlockerTest PUBLIC ${GTEST_INCLUDE_DIR}
                                                        ${CMAKE_CURRENT_SOURCE_DIR}/_mock)
