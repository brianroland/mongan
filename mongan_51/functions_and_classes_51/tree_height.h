//
// Created by Christopher Roland on 10/1/16.
//

#ifndef MONGAN_TREE_HEIGHT_H
#define MONGAN_TREE_HEIGHT_H

#include <cassert>

template<class T>
struct Node{
    Node * left;
    Node * right;
    T * data;
};

int height(const Node * root) {
    assert(root!=nullptr);

    

    return 1;
}


#endif //MONGAN_TREE_HEIGHT_H
