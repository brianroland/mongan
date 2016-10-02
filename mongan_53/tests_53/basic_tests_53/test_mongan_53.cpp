//
// Created by Christopher Roland on 10/1/16.
//

#include "gtest/gtest.h"
#include <stack>
#include <iostream>
#include <string>
#include "functions_and_classes_53/iterative_preorder_traversal.h"

using namespace std;

TEST(test_mongan_53, hello_world) {
    printf("\nhello world\n");
    printf("hello world\n");
}

TEST(test_mongan_53, create_and_use_stl_stack) {
    printf("\ncreate_and_use_stl_stack\n");
    stack<string *> * my_stack = new stack<string *>();
    my_stack->push(new string("apple"));

    cout << * my_stack->top() << endl;
    my_stack->pop();

    delete my_stack;
    printf("create_and_use_stl_stack\n");
}

TEST(test_mongan_53, test_iterative_preorder_walk) {
    printf("\ntest_iterative_preorder_walk\n");

    Node<string> * f = new Node<string>(new string("fig"));
    Node<string> * e = new Node<string>(new string("elderberry"), f, nullptr);
    Node<string> * d = new Node<string>(new string("date"));
    Node<string> * c = new Node<string>(new string("coconut"));
    Node<string> * b = new Node<string>(new string("blueberry"), d, e);
    Node<string> * a = new Node<string>(new string("apple"), b, c);

    IterativePreorderWalk(a);

    printf("test_iterative_preorder_walk\n");
}