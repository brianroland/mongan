cmake_minimum_required(VERSION 3.6)

set(HEADER_FILES stack.h)

set(SOURCE_FILES stack.cpp)

# define a static library (file with compiled classes and functions)
add_library(functions_and_classes_41 STATIC ${SOURCE_FILES} ${HEADER_FILES})