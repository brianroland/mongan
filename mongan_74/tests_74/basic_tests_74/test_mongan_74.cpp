//
// Created by Christopher Roland on 10/16/16.
//
#include <iostream>
#include <gtest/gtest.h>
#include "telephone_words.h"
using namespace std;

TEST(hello_world_0, hello_world) {
    printf("\nhello_world: beg()\n");
    printf("hello_world: end()\n");
}

TEST(test_get_character, test_get_character) {
    printf("\ntest_get_character: beg()\n");

    string c = GetCharacter(6,0);
    cout << "string c=" << c << endl;

    c = GetCharacter(7,2);
    cout << "string c=" << c << endl;

    printf("test_get_character: end()\n");
}
TEST(text_extend_word, test_extend_word) {
    printf("\ntest_extend_word\n");

    vector<int> number = {6,7};

    ExtendWord(number,"N");

    printf("test_extend_word\n");
}

TEST(test_enumerate_words_0, test_enumerate_words) {
    printf("\ntest_extend_word\n");

    vector<int> number = {6,7};

    EnumerateWords(number);

    printf("test_extend_word\n");
}