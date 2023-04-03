cmake_minimum_required(VERSION 3.13)

project(learningGTest)

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

add_executable(main main.cpp)
target_link_libraries(main gtest_main gmock_main)
