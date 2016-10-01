cmake_minimum_required(VERSION 3.6)
project(mongan)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp mongan_52/tests_52/basic_tests_52/test_mongan_52.cpp mongan_52/functions_and_classes_52/preorder_traversal.h mongan_52/functions_and_classes_52/preorder_traversal.cpp)
add_executable(run_mongan ${SOURCE_FILES})

include_directories(mongan_41)
add_subdirectory(mongan_41)

include_directories(mongan_42)
add_subdirectory(mongan_42)

include_directories(mongan_51)
add_subdirectory(mongan_51)

include_directories(mongan_52)
add_subdirectory(mongan_52)
