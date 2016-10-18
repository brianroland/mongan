//
// Created by Christopher Roland on 10/17/16.
//


#include <iostream>
#include "gtest/gtest.h"
#include "flatten_list.h"

using namespace std;

TEST(test_hello_world_0, test_hello_world) {
    printf("\ntest_hello_world_0: beg\n");
    printf("test_hello_world_0: end \n");
}

TEST(test_print_values_0, test_print_values) {
    printf("test_print_values_0: beg\n");

    Node * a = new Node();
    Node * b = new Node();
    Node * c = new Node();

    a->value_ = 0;
    b->value_ = 1;
    c->value_ = 2;

    a->next_ = b;
    b->next_ = c;

    PrintValues(a);

    delete c;
    delete b;
    delete a;

    printf("\ntest_print_values_0: end\n");
}

TEST(test_flatten_one_node, test_flatten) {
    printf("test_flatten_one_node: beg\n");

    Node * a = new Node();
    a->value_ = 0;
    Flatten(a);
    PrintValues(a);
    delete a;


    printf("\ntest_flatten_one_node: end\n");
}

TEST(test_flatten_three_nodes, test_flatten) {
    printf("\ntest_flatten_three_nodes: beg\n");

    Node * a = new Node();
    Node * b = new Node();
    Node * c = new Node();

    a->value_ = 0;
    b->value_ = 1;
    c->value_ = 2;

    a->next_ = b;
    b->next_ = c;

    Flatten(a);
    PrintValues(a);

    delete c;
    delete b;
    delete a;

    printf("test_flatten_three_nodes: end\n");
}

TEST(test_flatten_two_level, test_flatten) {
    printf("\ntest_flatten_two_level: beg\n");

    Node * a = new Node();
    Node * b = new Node();
    Node * c = new Node();
    Node * d = new Node();
    Node * e = new Node();
    Node * f = new Node();

    a->value_ = 0;
    b->value_ = 1;
    c->value_ = 2;
    d->value_ = 3;
    e->value_ = 4;
    f->value_ = 5;

    Connect(a, b);
    Connect(b, c);
    Connect(d, e);
    Connect(e, f);

    b->child_ = d;

    Flatten(a);
    PrintValues(a);

    delete f;
    delete e;
    delete d;
    delete c;
    delete b;
    delete a;

    printf("test_flatten_three_nodes: end\n");
}

TEST(test_flatten_two_level_1, test_flatten) {
    printf("\ntest_flatten_two_level_1: beg\n");

    Node * a = new Node();
    Node * b = new Node();
    Node * c = new Node();
    Node * d = new Node();
    Node * e = new Node();
    Node * f = new Node();
    Node * g = new Node();
    Node * h = new Node();
    Node * i = new Node();

    a->value_ = 0;
    b->value_ = 1;
    c->value_ = 2;
    d->value_ = 3;
    e->value_ = 4;
    f->value_ = 5;
    g->value_ = 6;
    h->value_ = 7;
    i->value_ = 8;


    Connect(a, b);
    Connect(b, c);
    Connect(d, e);
    Connect(e, f);
    Connect(g, h);
    Connect(h, i);

    b->child_ = d;
    c->child_ = g;

    Flatten(a);
    PrintValues(a);


    delete i;
    delete h;
    delete g;
    delete f;
    delete e;
    delete d;
    delete c;
    delete b;
    delete a;

    printf("test_flatten_two_level_1: end\n");
}