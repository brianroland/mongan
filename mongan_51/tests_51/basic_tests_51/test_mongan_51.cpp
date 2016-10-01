//
// Created by Christopher Roland on 10/1/16.
//

#include <iostream>
#include <functions_and_classes_51/tree_height.h>
#include "gtest/gtest.h"

TEST(test_mongan_51, hello_world) {
    printf("\nhello world\n");
}

TEST(test_mongan_51, test_max_int) {
    printf("\ntest_max_int: beg\n");
    ASSERT_EQ(5, MaxInt(3,5));
    ASSERT_EQ(5, MaxInt(5,3));
    printf("test_max_int: end\n");
}


TEST(test_mongan_51, test_height) {
    printf("\ntest_height: beg\n");

    Node<double> * e = new Node<double>(new double(10));
    Node<double> * d = new Node<double>(new double(20));
    Node<double> * c = new Node<double>(new double(30), e, nullptr);
    Node<double> * b = new Node<double>(new double(40));
    Node<double> * a = new Node<double>(new double(50), c, d);
    Node<double> * root = new Node<double>(new double(60), a, b);

    ASSERT_EQ(height(e), 1);
    ASSERT_EQ(height(c), 2);
    ASSERT_EQ(height(root), 4);
    printf("test_height: end\n");
}