cmake_minimum_required(VERSION 3.6)
project(mongan_53)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_53.cpp)
add_executable(run_mongan_53 ${SOURCE_FILES})

include_directories(functions_and_classes_53)

add_subdirectory(functions_and_classes_53)
add_subdirectory(tests_53)

target_link_libraries(run_mongan_53 functions_and_classes_53)