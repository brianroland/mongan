cmake_minimum_required(VERSION 3.6)
project(mongan_42)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_42.cpp)
add_executable(run_mongan_42 ${SOURCE_FILES})
include_directories(functions_and_classes_42)

add_subdirectory(functions_and_classes_42)
add_subdirectory(tests_42)

target_link_libraries(run_mongan_42 functions_and_classes_42)