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
    printf("data=%.2f\n", *node->data());
    delete node;
    printf("create_destroy_single_link_node: end\n");
}

TEST(test_mongan_42, insert_at_head) {
    printf("\ninsert_at_head: beg\n");

    //test that a single insertion results in the value put at the front
    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    list->InsertAfter(nullptr, new double(1.23));
    ASSERT_EQ(*list->GetDataAtFront(), 1.23);

    //test that a second insertion results in the second value at the front
    list->InsertAfter(nullptr, new double(2.34));
    ASSERT_EQ(*list->GetDataAtFront(), 2.34);

    //test that inserting after an address not in the data structure does not change the value of front
    SingleLinkNode<double> * singleton_data = new SingleLinkNode<double>(new double(3.45), nullptr);
    list->InsertAfter(singleton_data, new double(4.56));
    ASSERT_EQ(*list->GetDataAtFront(), 2.34);

    //check the value of is_empty
    ASSERT_EQ(list->IsEmpty(),false);

    printf("insert_at_head: end\n");
}

TEST(test_mongan_42, remove_from_head) {
    printf("\nremove_at_head: beg\n");
    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    list->InsertInFront(new double(1.23));
    ASSERT_EQ(*list->GetDataAtFront(), 1.23);
    ASSERT_EQ(list->Remove(list->head()), true);
    ASSERT_EQ(list->IsEmpty(), true);
    ASSERT_EQ(list->head(), nullptr);
    ASSERT_EQ(list->tail(), nullptr);
    printf("remove_at_head: end\n");
}

TEST(test_mongan_42, remove_from_middle) {
    printf("\nremove_from_middle: beg\n");
    SinglyLinkedList<double> * list = new SinglyLinkedList<double>();
    double * a = new double(1.23);
    double * b = new double(4.56);
    double * c = new double(7.89);


    list->InsertInFront(a);
    list->InsertInFront(b);
    list->InsertInFront(c);
    ASSERT_EQ(*list->GetDataAtFront(), *c);

    FindResult<double> * find_result_b = list->Find(b);
    ASSERT_EQ(find_result_b->found_, true);
    const SingleLinkNode<double> * middle = find_result_b->target_;
    ASSERT_EQ(middle->data(),b);

    printf("remove_from_middle: end\n");
}