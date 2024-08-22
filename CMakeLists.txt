cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME chess)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})

option(USE_SDL "Use SDL for UI" ON)
option(USE_CSFML "Use CSFML for UI" OFF)

project(${PROJECT_NAME} C)

# Sources

set(SOURCES
    src/main.c
    src/game.c
    src/board.c
)

include_directories(${PROJECT_NAME} src)

add_executable(${PROJECT_NAME} ${SOURCES})

# Libraries

set(BUILD_SHARED_LIBS OFF)

add_subdirectory(src/lib/utils)
add_subdirectory(src/lib/engine)

include_directories(src/lib/utils/include
                    src/lib/engine/include)

target_link_libraries(${PROJECT_NAME} utils engine)

#Tests

option(BUILD_TESTS "Build Chess tests" ON)
