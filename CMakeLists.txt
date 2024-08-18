cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME Chess)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})

#option(DSDL_STATIC "Build the static SDL library" ON)
#option(DSDL_IMAGE_STATIC "Build the static SDL_image library" ON)

project(${PROJECT_NAME} C)

set(SOURCES
    src/main.c
    src/game.c
    src/board.c
    src/renderer.c)

# Libraries
add_subdirectory(lib/SDL EXCLUDE_FROM_ALL)
add_subdirectory(lib/SDL_image EXCLUDE_FROM_ALL)

include_directories(lib/SDL/include 
                    lib/SDL_image/include)

add_executable(${PROJECT_NAME} ${SOURCES})

    
target_link_libraries(${PROJECT_NAME} 
    SDL2::SDL2
    SDL2_image::SDL2_image)