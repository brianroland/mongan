cmake_minimum_required(VERSION 3.6)

project(mongan_92)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_92.cpp)

add_executable(run_mongan_92 ${SOURCE_FILES})

include_directories(functions_and_classes_92)

add_subdirectory(functions_and_classes_92)

add_subdirectory(tests_92)

target_link_libraries(run_mongan_92 functions_and_classes_92)

target_link_libraries(run_mongan_92 pthread)