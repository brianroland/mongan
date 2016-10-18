cmake_minimum_required(VERSION 3.6)
project(mongan_45)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_45.cpp)
add_executable(run_mongan_45 ${SOURCE_FILES})
include_directories(functions_and_classes_45)

add_subdirectory(functions_and_classes_45)
add_subdirectory(tests_45)

target_link_libraries(run_mongan_45 functions_and_classes_45)