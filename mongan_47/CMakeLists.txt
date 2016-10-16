cmake_minimum_required(VERSION 3.6)
project(mongan_47)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_47.cpp)
add_executable(run_mongan_47 ${SOURCE_FILES})
include_directories(functions_and_classes_47)

add_subdirectory(functions_and_classes_47)
add_subdirectory(tests_47)

target_link_libraries(run_mongan_47 functions_and_classes_47)