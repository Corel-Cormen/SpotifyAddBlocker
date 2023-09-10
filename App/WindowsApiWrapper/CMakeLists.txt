set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/_src/WindowsWrapper.cpp)

add_library(WindowsApiWrapper ${SOURCES})

target_include_directories(WindowsApiWrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/_inc)
