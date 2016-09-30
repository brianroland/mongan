//
// Created by Christopher Roland on 9/30/16.
//
#include <iostream>
#include "gtest/gtest.h"
#include "sl_list.h"

TEST(test_mongan_42, hello_world) {
    printf("\nhello world\n");
}

TEST(test_mongan_42, create_destroy_single_link_node) {
    printf("\ncreate_destroy_single_link_node: beg\n");
    SingleLinkNode<double> *node = new SingleLinkNode<double>(new double(1.23), nullptr);
    printf("data=%.2f\n", *node->getData());
    delete node;
    printf("create_destroy_single_link_node: end\n");
}

TEST(test_mongan_42, insert_at_head) {
    printf("\ninsert_at_head: beg\n");

    //test that a single insertion results in the value put at the front
    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    list->insertAfter(nullptr, new double(1.23));
    ASSERT_EQ(*list->front(), 1.23);

    //test that a second insertion results in the second value at the front
    list->insertAfter(nullptr, new double(2.34));
    ASSERT_EQ(*list->front(), 2.34);


    //test that inserting after an address not in the data structure does not change the value of front
    SingleLinkNode<double> * singleton_data = new SingleLinkNode<double>(new double(3.45), nullptr);
    list->insertAfter(singleton_data, new double(4.56));
    ASSERT_EQ(*list->front(), 2.34);

    //check the value of is_empty
    ASSERT_EQ(list->isEmpty(),false);

    printf("insert_at_head: end\n");
}