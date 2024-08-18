cmake_minimum_required(VERSION 3.5)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})

option(DSDL_STATIC "Build the static SDL library" ON)

project(Chess C)

include_directories(include)

set(SOURCES
    src/main.c)

# Libraries
add_subdirectory(lib/SDL EXCLUDE_FROM_ALL)

add_executable(Chess ${SOURCES})

target_link_libraries(Chess SDL2::SDL2-static)