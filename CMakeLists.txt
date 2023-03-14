cmake_minimum_required(VERSION 3.13)

project(newLibrary)

add_library(sumLibrary STATIC new_library.cpp)

add_executable(mainApp main.cpp)

target_link_libraries(mainApp sumLibrary)