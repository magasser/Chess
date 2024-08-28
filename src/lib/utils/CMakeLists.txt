cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME utils)

project(${PROJECT_NAME} 
        VERSION 1.0.0
        LANGUAGES C
        DESCRIPTION "Utils")

include_directories(include)

set(UTILS_SOURCES src/list.c)

option(UTILS_BUILD_TESTS "Build utils tests" ON)


if (UTILS_BUILD_TESTS)
    set(UTILS_TEST_PROJECT_NAME utils_tests) 

    set(UTILS_TEST_SOURCES 
    src/utils/list.c 
    tests/utils/list.tests.c)   
    
    add_executable(${UTILS_TEST_PROJECT_NAME} ${UTILS_TEST_SOURCES})

    add_subdirectory(${CMAKE_SOURCE_DIR}/lib/Unity Unity EXCLUDE_FROM_ALL)

    target_link_libraries(${UTILS_TEST_PROJECT_NAME} unity)

    enable_testing()

    add_test(NAME ${UTILS_TEST_PROJECT_NAME} COMMAND ${UTILS_TEST_PROJECT_NAME})
endif()

if(NOT TARGET ${PROJECT_NAME})
    add_library(${PROJECT_NAME} STATIC)

    target_sources(${PROJECT_NAME}
                    PRIVATE
                    ${UTILS_SOURCES})
endif()
