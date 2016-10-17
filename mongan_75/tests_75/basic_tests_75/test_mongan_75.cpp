//
// Created by Christopher Roland on 10/16/16.
//
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "telephone_words_iterative.h"
using namespace std;

TEST(hello_world_0, hello_world) {
    printf("\nhello_world: beg()\n");
    printf("hello_world: end()\n");
}
TEST(test_case_67, test_case) {
    printf("\nhello_world: beg()\n");

    EnumerateWordsIterative(vector<int>({6,7}));

    printf("hello_world: end()\n");
}
TEST(test_case_23, test_case) {
    printf("\nhello_world: beg()\n");

    EnumerateWordsIterative(vector<int>({2,3}));

    printf("hello_world: end()\n");
}