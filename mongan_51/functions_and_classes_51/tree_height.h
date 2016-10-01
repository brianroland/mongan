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

    if (root==nullptr) {return 0;}

    int height_of_left_subtree = height(root->left_);
    int height_of_right_subtree = height(root->right_);

    int larger_height = 1 + MaxInt(height_of_left_subtree, height_of_right_subtree);

    return larger_height;
}


#endif //MONGAN_TREE_HEIGHT_H
