cmake_minimum_required(VERSION 3.6)
project(mongan_61)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_61.cpp)
add_executable(run_mongan_61 ${SOURCE_FILES})

include_directories(functions_and_classes_61)

add_subdirectory(functions_and_classes_61)
add_subdirectory(tests_61)

target_link_libraries(run_mongan_61 functions_and_classes_61)