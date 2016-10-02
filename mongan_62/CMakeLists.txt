cmake_minimum_required(VERSION 3.6)
project(mongan_62)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_62.cpp)
add_executable(run_mongan_62 ${SOURCE_FILES})

include_directories(functions_and_classes_62)

add_subdirectory(functions_and_classes_62)
add_subdirectory(tests_62)

target_link_libraries(run_mongan_62 functions_and_classes_62)