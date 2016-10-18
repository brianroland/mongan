//
// Created by Christopher Roland on 10/2/16.
//


#include "gtest/gtest.h"
#include <string>
#include "string_to_int.h"

using namespace std;

TEST(hello_world, test_mongan_64) {
    printf("\nhello_world: beg\n");
    printf("hello_world: end\n");
}

TEST(test_char_to_int, test_mongan_64) {
    printf("\ntest_char_to_int: beg\n");
    char a = '7';
    int i = CharToInt(a);
    ASSERT_EQ(i,7);
    printf("test_char_to_int: end\n");
}

TEST(test_string_to_int, test_mongan_64) {
    printf("\ntest_char_to_int: beg\n");
    string s = string("-123");
    int i = StringToInt(s);
    ASSERT_EQ(i,-123);
    printf("test_char_to_int: end\n");
}

TEST(test_string_to_int_1, test_mongan_64) {
    printf("\ntest_string_to_int_1: beg\n");
    string s = string("456");
    int i = StringToInt(s);
    ASSERT_EQ(i, 456);
    printf("test_string_to_int_1: end\n");
}
TEST(test_digit_to_char, test_mongan_64) {
    printf("\ntest_digit_to_char: beg\n");

    char a = DigitToChar(7);
    cout << "a=" << a << endl;
    ASSERT_EQ(a,'7');

    printf("test_digit_to_chard: end\n");
}
TEST(test_int_to_string, test_mongan_64) {
    printf("\ntest_int_to_string: beg\n");

    string out = IntToString(-72);
    cout << "out=" << out << endl;
    ASSERT_EQ(out,"-72");

    printf("test_int_to_string: end\n");
}

