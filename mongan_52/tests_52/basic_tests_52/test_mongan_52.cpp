//
// Created by Christopher Roland on 10/1/16.
//
#include <iostream>
#include "gtest/gtest.h"
#include <functions_and_classes_51/tree_height.h>
#include <functions_and_classes_52/preorder_traversal.h>

using namespace std;

TEST(test_mongan_52, hello_world) {
    printf("\nhello_world: beg\n");
    printf("hello_world: end\n");
}

TEST(test_mongan_52, preorder_traversal) {
    printf("\npreorder_traversal: beg\n");

    Node<string> * g = new Node<string>(new string("guava"));
    Node<string> * f = new Node<string>(new string("fig"));
    Node<string> * e = new Node<string>(new string("eggplant"));
    Node<string> * d = new Node<string>(new string("date"));
    Node<string> * c = new Node<string>(new string("coconut"), g, nullptr);
    Node<string> * b = new Node<string>(new string("blueberry"), e, f);
    Node<string> * a = new Node<string>(new string("apple"), c, d);
    Node<string> * root = new Node<string>(new string("raisin"), a, b);

    PreorderTraversal(root);

    printf("preorder_traversal: end\n");
}


