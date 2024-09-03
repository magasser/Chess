cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME engine)

project(${PROJECT_NAME} 
        VERSION 1.0.0
        LANGUAGES C
        DESCRIPTION "UI engine")

include_directories(include)

set(ENGINE_SOURCES
    src/renderer.c
    src/window.c
    src/components/button.c)

if(USE_SDL)
    list(APPEND ENGINE_SOURCES 
        src/SDL/ui.c
        src/SDL/window.c
        src/SDL/renderer.c
        src/SDL/event.c
        src/SDL/texture.c
    )
elseif(USE_CSFML)
    list(APPEND ENGINE_SOURCES 
        src/CSFML/ui.c
        src/CSFML/window.c
        src/CSFML/renderer.c
        src/CSFML/texture.c
    )
endif()

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
                PRIVATE
                ${ENGINE_SOURCES})

# Libraries

set(BUILD_SHARED_LIBS OFF)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/lib/utils utils EXCLUDE_FROM_ALL)

include_directories(${CMAKE_SOURCE_DIR}/src/lib/utils/include)

target_link_libraries(${PROJECT_NAME} utils)

if(USE_SDL)
    add_subdirectory(${CMAKE_SOURCE_DIR}/lib/SDL SDL EXCLUDE_FROM_ALL)
    add_subdirectory(${CMAKE_SOURCE_DIR}/lib/SDL_image SDL_image EXCLUDE_FROM_ALL)
elseif(USE_CSFML)
endif()

if(USE_SDL)
    include_directories(${CMAKE_SOURCE_DIR}/lib/SDL/include
                        ${CMAKE_SOURCE_DIR}/lib/SDL_image/include)
elseif(USE_CSFML)
endif()    

if(USE_SDL)
    target_link_libraries(${PROJECT_NAME} 
    SDL2::SDL2-static
    SDL2_image::SDL2_image-static)
elseif(USE_CSFML)
endif()
