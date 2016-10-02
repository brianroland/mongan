//
// Created by Christopher Roland on 10/2/16.
//


#include "gtest/gtest.h"
#include <string>
#include <functions_and_classes_62/remove_characters.h>

using namespace std;

TEST(hello_world, test_mongan_62) {
    printf("\nhello_world: beg\n");
    printf("hello_world: end\n");
}
TEST(test_resize, test_mongan_62) {
    printf("\ntest_resize: beg\n");
    string s("blanket");
    s.resize(4);                        //reduce the size of the string with a O(1) operation
    cout << s << endl;
    printf("test_resize: end\n");
}

TEST(example_1, test_mongan_62) {
    printf("\nexample_1: beg\n");

    string target = "apple";
    string remove = "p";
    RemoveCharacters(&target, &remove);

    cout << target << endl;
    ASSERT_EQ(target, "ale");

    printf("example_1: end\n");
}

TEST(example_2, test_mongan_62) {
    printf("\nexample_1: beg\n");

    string target = "independent";
    string remove = "ie";
    RemoveCharacters(&target, &remove);
    cout << target << endl;
    ASSERT_EQ(target, "ndpndnt");

    printf("example_2: end\n");
}

