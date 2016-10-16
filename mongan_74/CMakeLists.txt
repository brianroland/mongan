cmake_minimum_required(VERSION 3.6)
project(mongan_74)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_74.cpp)
add_executable(run_mongan_74 ${SOURCE_FILES})

include_directories(functions_and_classes_74)

add_subdirectory(functions_and_classes_74)
add_subdirectory(tests_74)

target_link_libraries(run_mongan_74 functions_and_classes_74)