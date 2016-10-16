//
// Created by Christopher Roland on 9/30/16.
//
#include <iostream>
#include "gtest/gtest.h"
#include "null_or_cycle.h"
#include <cstdio>
#include <iostream>

TEST(hello_world_0, hello_world) {
    printf("\nhello world\n");
}

TEST(one_node_with_null, one_node) {
    printf("\none_node_with_null: beg()\n");

    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    list->InsertInFront(new double(0.0));

    bool outcome = DoesContainCycle(list);

    printf("DoesContainCycle=%d\n", outcome);


    delete list;

    printf("one_node_with_null: end()\n");
}

TEST(one_node_with_cycle, one_node) {
    printf("\none_node_with_cycle: beg()\n");

    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    list->InsertInFront(new double(0.0));
    list->head()->set_next(list->head());

    bool outcome = DoesContainCycle(list);

    printf("DoesContainCycle=%d\n", outcome);


    delete list;

    printf("one_node_with_cycle: end()\n");
}

TEST(three_nodes_with_null, three_nodes) {
    printf("\nthree_nodes_with_null: beg()\n");

    //nodes with keys 0.0, 1.0, 2.0, the tail points to a null
    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    list->InsertAfter(nullptr, new double(0.0));
    list->InsertAfter(list->head(), new double(1.0));
    list->InsertAfter(list->head(), new double(2.0));

    bool outcome = DoesContainCycle(list);

    printf("DoesContainCycle=%d\n", outcome);

    delete list;

    printf("three_nodes_with_null: end()\n");
}

TEST(three_nodes_with_cycles, three_nodes) {
    printf("\nthree_nodes_with_cycle: beg()\n");

    //nodes with keys 0.0, 1.0, 2.0, the tail points to a null
    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    list->InsertAfter(nullptr, new double(0.0));
    list->InsertAfter(list->head(), new double(1.0));
    list->InsertAfter(list->head(), new double(2.0));
    list->tail()->set_next(list->head()->next());

    bool outcome = DoesContainCycle(list);

    printf("DoesContainCycle=%d\n", outcome);

    delete list;

    printf("three_nodes_with_cycle: end()\n");
}

TEST(four_nodes_with_null, four_nodes) {
    printf("\nfour_nodes_with_null: beg()\n");

    //nodes with keys 0.0, 1.0, 2.0, the tail points to a null
    SinglyLinkedList<double> *list = new SinglyLinkedList<double>();
    list->InsertAfter(nullptr, new double(0.0));
    list->InsertAfter(list->head(), new double(1.0));
    list->InsertAfter(list->head(), new double(2.0));
    list->InsertAfter(list->head(), new double(3.0));

    bool outcome = DoesContainCycle(list);

    printf("DoesContainCycle=%d\n", outcome);

    delete list;

    printf("four_nodes_with_null: end()\n");
}

TEST(four_nodes_with_cycles, four_nodes) {
    printf("\nfour_nodes_with_cycle: beg()\n");

    //nodes with keys 0.0, 1.0, 2.0, the tail points to a null
    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    list->InsertAfter(nullptr, new double(0.0));
    list->InsertAfter(list->head(), new double(1.0));
    list->InsertAfter(list->head(), new double(2.0));
    list->InsertAfter(list->head(), new double(3.0));
    list->tail()->set_next(list->head()->next());

    bool outcome = DoesContainCycle(list);

    printf("DoesContainCycle=%d\n", outcome);

    delete list;

    printf("four_nodes_with_cycle: end()\n");
}