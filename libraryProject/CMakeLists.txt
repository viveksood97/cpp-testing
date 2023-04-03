cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 11)

project(learningTestFixtures)
include(FetchContent)
FetchContent_Declare(googletest
                        GIT_REPOSITORY https://github.com/google/googletest
                        GIT_TAG v1.13.0)
FetchContent_GetProperties(googletest)
if(NOT FetchContent_Populated)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_library(commonLibrary LibraryCode.cpp)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp commonLibrary)

add_executable(unitTestRunner testRunner.cpp)
target_link_libraries(unitTestRunner commonLibrary gtest_main gmock_main pthread)

