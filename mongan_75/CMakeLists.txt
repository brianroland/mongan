cmake_minimum_required(VERSION 3.6)
project(mongan_75)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_75.cpp)
add_executable(run_mongan_75 ${SOURCE_FILES})

include_directories(functions_and_classes_75)

add_subdirectory(functions_and_classes_75)
add_subdirectory(tests_75)

target_link_libraries(run_mongan_75 functions_and_classes_75)