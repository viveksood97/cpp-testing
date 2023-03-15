cmake_minimum_required(VERSION 3.13)

project(newLibrary)

# get googletest
include(FetchContent)
FetchContent_Declare(googletest
                        GIT_REPOSITORY https://github.com/google/googletest
                        GIT_TAG v1.13.0)
FetchContent_GetProperties(googletest)
if(NOT FetchContent_Populated)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_library(sumLibrary STATIC new_library.cpp)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp sumLibrary)

add_executable(testRunner test.cpp)
target_link_libraries(testRunner sumLibrary gtest_main gmock_main)

