cmake_minimum_required(VERSION 3.6)

set(HEADER_FILES sl_list.h)

set(SOURCE_FILES sl_list.cpp)

add_library(functions_and_classes_42 STATIC ${SOURCE_FILES} ${HEADER_FILES})