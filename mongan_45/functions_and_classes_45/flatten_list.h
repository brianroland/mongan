//
// Created by Christopher Roland on 10/18/16.
//

#ifndef MONGAN_FLATTEN_LIST_H
#define MONGAN_FLATTEN_LIST_H

#include <iostream>
#include <stack>

struct Node {
    Node * prev_;
    Node * next_;
    Node * child_;
    int value_;
};

void Flatten(Node * head);

void Insert(Node * head, Node * tail, Node * target);

void PrintValues(Node * head);

void Connect(Node* left, Node * right);

#endif //MONGAN_FLATTEN_LIST_H
