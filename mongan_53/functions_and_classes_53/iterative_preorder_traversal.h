//
// Created by Christopher Roland on 10/1/16.
//

#ifndef MONGAN_ITERATIVE_PREORDER_TRAVERSAL_H
#define MONGAN_ITERATIVE_PREORDER_TRAVERSAL_H

#include <stack>
#include <functions_and_classes_51/tree_height.h>
#include <iostream>

using namespace std;

template<class T>
void IterativePreorderWalk(Node<T> * root) {

    if (root==nullptr) { return; }


    stack<Node<T> *> * my_stack = new stack<Node<T> *>();

    my_stack->push(root);
    cout << *root->data_ << endl;
    *root->state_ = "printed";

    while(!my_stack->empty()) {

        Node<T> * top = my_stack->top();

        if (top->left_ != nullptr and *top->left_->state_ != "printed") {
            my_stack->push(top->left_);
            cout << *top->left_->data_ << endl;
            *top->left_->state_ = "printed";

        } else if (top->right_ != nullptr and *top->right_->state_ != "printed") {
            my_stack->push(top->right_);
            cout << *top->right_->data_ << endl;
            *top->right_->state_ = "printed";

        } else {
            my_stack->pop();
        }
    }

    delete my_stack;
}

template<class T>
void IterativePreorderWalk_Solution(Node<T> * root) {

    if (root==nullptr) { return; }


    stack<Node<T> *> * my_stack = new stack<Node<T> *>();

    my_stack->push(root);


    while(!my_stack->empty()) {

        Node<T> * top = my_stack->top();
        my_stack->pop();
        cout << *top->data_ << endl;

        if (top->right_ != nullptr) { my_stack->push(top->right_); }
        if (top->left_ != nullptr) { my_stack->push(top->left_); }

    }

    delete my_stack;
}


#endif //MONGAN_ITERATIVE_PREORDER_TRAVERSAL_H
