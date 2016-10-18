cmake_minimum_required(VERSION 3.6)
project(mongan_44)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_44.cpp run_mongan_44.cpp)
add_executable(run_mongan_44 ${SOURCE_FILES})
include_directories(functions_and_classes_44)

add_subdirectory(functions_and_classes_44)
add_subdirectory(tests_44)

target_link_libraries(run_mongan_44 functions_and_classes_44)