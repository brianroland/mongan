cmake_minimum_required(VERSION 3.6)
project(mongan_52)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_52.cpp)
add_executable(run_mongan_52 ${SOURCE_FILES})
include_directories(functions_and_classes_52)

add_subdirectory(functions_and_classes_52)
add_subdirectory(tests_52)

target_link_libraries(run_mongan_52 functions_and_classes_52)