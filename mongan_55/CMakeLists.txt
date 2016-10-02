cmake_minimum_required(VERSION 3.6)
project(mongan_55)

add_definitions(-std=c++11)

set(SOURCE_FILES run_mongan_55.cpp)
add_executable(run_mongan_55 ${SOURCE_FILES})

include_directories(functions_and_classes_55)

add_subdirectory(functions_and_classes_55)
add_subdirectory(tests_55)

target_link_libraries(run_mongan_55 functions_and_classes_55)