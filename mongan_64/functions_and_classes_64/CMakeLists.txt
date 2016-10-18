cmake_minimum_required(VERSION 3.6)

set(SOURCE_FILES string_to_int.cpp)

set(HEADER_FILES string_to_int.h)

add_library(functions_and_classes_64 STATIC ${SOURCE_FILES} ${HEADER_FILES})