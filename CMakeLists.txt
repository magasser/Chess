cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME Chess)

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
    src/utils/list.c
    src/UI/renderer.c
)

include_directories(src)

if(USE_SDL)
    list(APPEND SOURCES 
        src/UI/SDL/ui.c
        src/UI/SDL/window.c
        src/UI/SDL/renderer.c
        src/UI/SDL/event.c
    )
elseif(USE_CSFML)
    list(APPEND SOURCES 
        src/UI/CSFML/ui.c
        src/UI/CSFML/window.c
        src/UI/CSFML/renderer.c
    )
endif()

add_executable(${PROJECT_NAME} ${SOURCES})

# Libraries

set(BUILD_SHARED_LIBS OFF)

if(USE_SDL)
    add_subdirectory(lib/SDL EXCLUDE_FROM_ALL)
    add_subdirectory(lib/SDL_image EXCLUDE_FROM_ALL)
elseif(USE_CSFML)
endif()

if(USE_SDL)
    include_directories(lib/SDL/include
                        lib/SDL_image/include)
elseif(USE_CSFML)
endif()
    

if(USE_SDL)
    target_link_libraries(${PROJECT_NAME} 
    SDL2::SDL2-static
    SDL2_image::SDL2_image-static)
elseif(USE_CSFML)
endif()

#Tests

option(BUILD_TESTS "Build Chess tests" ON)

if (BUILD_TESTS)
    set(TEST_PROJECT_NAME ChessTests)

    set(TEST_SOURCES
        src/utils/list.c
        tests/utils/list.tests.c
    )

    add_executable(${TEST_PROJECT_NAME} ${TEST_SOURCES})

    add_subdirectory(lib/Unity EXCLUDE_FROM_ALL)

    target_link_libraries(${TEST_PROJECT_NAME} unity)

    enable_testing()

    add_test(NAME ${TEST_PROJECT_NAME} COMMAND ${TEST_PROJECT_NAME})
endif()
