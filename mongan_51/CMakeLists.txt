cmake_minimum_required(VERSION 3.6)
project(mongan_51)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_51.cpp)
add_executable(run_mongan_51 ${SOURCE_FILES})
include_directories(functions_and_classes_51)

add_subdirectory(functions_and_classes_51)
add_subdirectory(tests_51)

target_link_libraries(run_mongan_51 functions_and_classes_51)