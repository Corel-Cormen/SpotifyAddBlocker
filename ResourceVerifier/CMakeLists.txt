set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/_src/WinResourceVerifer.cpp)

add_library(ResourceVerifier ${SOURCES})

target_include_directories(ResourceVerifier PUBLIC
                            ${COMMON_TOOLS_INCLUDE_DIR}
                            ${FMT_INCLUDE_DIR}
                            ${CMAKE_CURRENT_SOURCE_DIR}/_inc)
