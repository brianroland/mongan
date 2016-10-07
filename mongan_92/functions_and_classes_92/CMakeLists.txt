cmake_minimum_required(VERSION 3.6)

set(SOURCE_FILES producer_consumer.cpp)

set(HEADER_FILES producer_consumer.h)

add_library(functions_and_classes_92 STATIC ${SOURCE_FILES} ${HEADER_FILES})