//
// Created by Christopher Roland on 10/2/16.
//

#include <algorithm>
#include "gtest/gtest.h"
#include <functions_and_classes_51/tree_height.h>
#include <functions_and_classes_55/remove_characters.h>
#include <functions_and_classes_52/preorder_traversal.h>

using namespace std;

TEST(test_mongan_55, hello_world) {
    printf("\nhello_world: beg\n");
    printf("hello_world: end\n");
}

TEST(test_mongan_55, test_count_nodes) {
    printf("\ntest_count_nodes: beg\n");

    Node<int> * e = new Node<int>(new int(7));
    Node<int> * d = new Node<int>(new int(5));
    Node<int> * c = new Node<int>(new int(4));
    Node<int> * b = new Node<int>(new int(9), d, e);
    Node<int> * a = new Node<int>(new int(1), b, c);
    ASSERT_EQ( CountNodesInTree(a), 5);

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    printf("test_count_nodes: end\n");
}

TEST(test_mongan_55, test_put_nodes_in_array) {
    printf("\ntest_put_nodes_in_array: beg\n");

    Node<int> * e = new Node<int>(new int(7));
    Node<int> * d = new Node<int>(new int(5));
    Node<int> * c = new Node<int>(new int(4));
    Node<int> * b = new Node<int>(new int(9), d, e);
    Node<int> * a = new Node<int>(new int(1), b, c);

    int num_nodes = CountNodesInTree(a);
    Node<int> ** base = new Node<int>*[num_nodes];
    int * curr = new int(0);

    PutNodesInArray(a, base, curr);
    ASSERT_EQ(base[0], a);
    ASSERT_EQ(base[4], c);

    delete curr;
    delete[] base;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    printf("test_put_nodes_in_array: end\n");
}

TEST(test_mongan_55, test_sort_array_of_int_pointers) {
    printf("\ntest_put_nodes_in_array: beg\n");

    Node<int> * a = new Node<int>(new int(1));
    Node<int> * b = new Node<int>(new int(2));
    Node<int> * c = new Node<int>(new int(3));

    Node<int> ** base = new Node<int>*[3];
    base[0] = b;
    base[1] = c;
    base[2] = a;
    for (auto i=0; i<3; i++) { cout << *base[i]->data_ << endl; }

    sort(base, base+3, LessThan<int>);
    for (auto i=0; i<3; i++) { cout << *base[i]->data_ << endl; }


    delete a;
    delete b;
    delete c;
    delete[] base;

    printf("test_put_nodes_in_array: end\n");
}

TEST(test_mongan_55, test_heapify) {
    //A more effective test would assert on the sequence of the output from the pre-order walk
    printf("\ntest_heapify: beg\n");

    Node<int> * e = new Node<int>(new int(7));
    Node<int> * d = new Node<int>(new int(5));
    Node<int> * c = new Node<int>(new int(4));
    Node<int> * b = new Node<int>(new int(9), d, e);
    Node<int> * a = new Node<int>(new int(1), b, c);


    Node<int> * heap_root = HeapifyTheTreeUsingArraySort(a);

    PreorderTraversal(heap_root);

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    printf("test_heapify: end\n");
}