cmake_minimum_required(VERSION 3.6)

project(mongan)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(run_mongan ${SOURCE_FILES})

include_directories(mongan_41)
add_subdirectory(mongan_41)

include_directories(mongan_42)
add_subdirectory(mongan_42)

include_directories(mongan_44)
add_subdirectory(mongan_44)

include_directories(mongan_47)
add_subdirectory(mongan_47)

include_directories(mongan_51)
add_subdirectory(mongan_51)

include_directories(mongan_52)
add_subdirectory(mongan_52)

include_directories(mongan_53)
add_subdirectory(mongan_53)

include_directories(mongan_55)
add_subdirectory(mongan_55)

include_directories(mongan_61)
add_subdirectory(mongan_61)

include_directories(mongan_62)
add_subdirectory(mongan_62)

include_directories(mongan_74)
add_subdirectory(mongan_74)

include_directories(mongan_75)
add_subdirectory(mongan_75)

include_directories(mongan_92)
add_subdirectory(mongan_92)