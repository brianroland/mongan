//
// Created by Christopher Roland on 10/2/16.
//


#include "gtest/gtest.h"
#include <functions_and_classes_61/first_nonrepeat.h>

using namespace std;

TEST(test_mongan_61, hello_world) {
    printf("\nhello_world: beg\n");
    printf("hello_world: end\n");
}
TEST(test_mongan_61, test_apple) {
    printf("\ntest_apple: beg\n");

    string s("apple");
    char c = FirstNonrepeat(s);
    ASSERT_EQ(c,'a');
    printf("test_apple: end\n");
}
TEST(aabbccdee, test_example) {
    printf("\naabbccdee: beg\n");
    string s("aabbccdee");
    char c = FirstNonrepeat(s);
    ASSERT_EQ(c,'d');
    printf("aabbccdee: end\n");
}
