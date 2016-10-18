cmake_minimum_required(VERSION 3.6)
project(mongan_64)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_64.cpp)
add_executable(run_mongan_64 ${SOURCE_FILES})

include_directories(functions_and_classes_64)

add_subdirectory(functions_and_classes_64)
add_subdirectory(tests_64)

target_link_libraries(run_mongan_64 functions_and_classes_64)