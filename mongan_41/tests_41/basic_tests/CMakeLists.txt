# Each CMake file says how to assemble the files in the same folder same level, perhaps in combination
# with executables, libraries, or source that exists at lower levels in the file hierarchy



# define an executable called run_tests
add_executable(test_mongan_41 test_mongan_41.cpp)

# when assembling the object files to make run_tests, include static libraries gtest, gtest_main, functions_and_classes_41
target_link_libraries(test_mongan_41 gtest gtest_main)

# how does this CMake file know about a library called functions_and_classes_41
target_link_libraries(test_mongan_41 functions_and_classes_41)