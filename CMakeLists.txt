cmake_minimum_required(VERSION 3.6)
project(mongan)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(run_mongan ${SOURCE_FILES})

include_directories(mongan_41)
add_subdirectory(mongan_41)

include_directories(mongan_42)
add_subdirectory(mongan_42)
