//
// Created by Christopher Roland on 10/2/16.
//

#ifndef MONGAN_BINARY_TREE_TO_HEAP_H
#define MONGAN_BINARY_TREE_TO_HEAP_H

#include <functions_and_classes_51/tree_height.h>

template<class T>
bool LessThan(Node<T> * x, Node<T> * y) { return (*x->data_ < *y->data_); }

int Left(int i) { return (2*i+1);}
int Right(int i) { return (2*i+2);}

template<class T>
int CountNodesInTree(Node<T> * root) {
    //touch each node once, this is Theta(n)
    if (root==nullptr) { return 0; }

    int nodes_in_left_subtree = CountNodesInTree(root->left_);
    int nodes_in_right_subtree = CountNodesInTree(root->right_);
    return 1 + nodes_in_left_subtree + nodes_in_right_subtree;
}

template<class T>
void PutNodesInArray(Node<T> * root, Node<T> ** base, int * curr) {

    if (root==nullptr) { return; }

    base[*curr] = root;
    *curr +=1;
    PutNodesInArray(root->left_, base, curr);
    PutNodesInArray(root->right_, base, curr);
}

template<class T>
void NullifyChildPointers(Node<T> ** base, int num_nodes) {

    for (int i=0; i< num_nodes; i++) {
        base[i]->left_ = nullptr;
        base[i]->right_ = nullptr;
    }
}


template<class T>
Node<T> * HeapifyTheTreeUsingArraySort(Node<T> * root) {

    int num_nodes = CountNodesInTree(root);
    Node<T> ** base = new Node<T>*[num_nodes];
    int * curr = new int(0);

    PutNodesInArray(root, base, curr);
    NullifyChildPointers(base, num_nodes);
    sort(base, base+num_nodes, LessThan<T>);


    //create min-heap
    for (auto i=0; i < num_nodes; i++) {

        if (Left(i) < num_nodes) { base[i]->left_ = base[Left(i)]; }
        if (Right(i) < num_nodes) { base[i]->right_ = base[Right(i)]; }
    }

    delete curr;
    delete[] base;
    return base[0];
}




#endif //MONGAN_BINARY_TREE_TO_HEAP_H
