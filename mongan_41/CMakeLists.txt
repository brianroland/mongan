cmake_minimum_required(VERSION 3.6)
project(mongan_41)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_41.cpp)
add_executable(run_mongan_41 ${SOURCE_FILES})
include_directories(functions_and_classes_41)

add_subdirectory(functions_and_classes_41)
add_subdirectory(tests_41)

target_link_libraries(run_mongan_41 functions_and_classes_41)