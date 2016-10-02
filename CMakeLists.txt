cmake_minimum_required(VERSION 3.6)
project(mongan)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp mongan_53/functions_and_classes_53/iterative_preorder_traversal.cpp mongan_53/functions_and_classes_53/iterative_preorder_traversal.h mongan_53/tests_53/basic_tests_53/test_mongan_53.cpp mongan_55/run_mongan_55.cpp mongan_55/functions_and_classes_55/binary_tree_to_heap.h mongan_55/functions_and_classes_55/binary_tree_to_heap.cpp mongan_55/tests_55/basic_tests_55/test_mongan_55.cpp)
add_executable(run_mongan ${SOURCE_FILES})

include_directories(mongan_41)
add_subdirectory(mongan_41)

include_directories(mongan_42)
add_subdirectory(mongan_42)

include_directories(mongan_51)
add_subdirectory(mongan_51)

include_directories(mongan_52)
add_subdirectory(mongan_52)

include_directories(mongan_53)
add_subdirectory(mongan_53)

include_directories(mongan_55)
add_subdirectory(mongan_55)