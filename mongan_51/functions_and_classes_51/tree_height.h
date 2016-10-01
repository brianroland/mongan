//
// Created by Christopher Roland on 10/1/16.
//

#ifndef MONGAN_TREE_HEIGHT_H
#define MONGAN_TREE_HEIGHT_H

#include <cassert>

template<class T>
struct Node{
    Node<T> * left_;
    Node<T> * right_;
    T * data_;
    Node(T * data, Node<T> * left=nullptr, Node<T> * right=nullptr)
            : data_(data), left_(left), right_(right) {}
};

int MaxInt(int a, int b) {
    return (b>a) ? b : a;
}

template<class T>
int height(const Node<T> * root) {
    assert(root!=nullptr);

    int height_via_left_subtree=0;
    int height_via_right_subtree=0;

    if (root->left_!=nullptr) {
        height_via_left_subtree = 1 + height(root->left_);
    }
    if (root->right_!=nullptr) {
        height_via_right_subtree = 1 + height(root->right_);
    }

    int larger_height = MaxInt(height_via_left_subtree, height_via_right_subtree);

    return larger_height;
}


#endif //MONGAN_TREE_HEIGHT_H
