//
// Created by Christopher Roland on 10/1/16.
//

#ifndef MONGAN_PREORDER_TRAVERSAL_H
#define MONGAN_PREORDER_TRAVERSAL_H

#include <iostream>
#include <functions_and_classes_51/tree_height.h>

template<class T>
void PreorderTraversal(Node<T> * root) {

    if (root==nullptr) { return;}

    std::cout << *root->data_ << std::endl;
    PreorderTraversal(root->left_);
    PreorderTraversal(root->right_);

}


#endif //MONGAN_PREORDER_TRAVERSAL_H



