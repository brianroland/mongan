//
// Created by Christopher Roland on 10/18/16.
//

#ifndef MONGAN_FLATTEN_LIST_H
#define MONGAN_FLATTEN_LIST_H

struct Node {
    Node * prev_;
    Node * next_;
    Node * child_;
    int value_;
};

void Flatten(Node * head) {

    


}

void Insert(Node * head, Node * tail, Node * target) {
    //insert list between tail and tail->next, O(1) operation

    assert(head!=nullptr);
    assert(tail!=nullptr);
    assert(target!=nullptr);

    target->next_ = head;
    head->prev_ = target;

    if (target->next_ != nullptr) {
        tail->next_ = target->next_;
        target->next_->prev_ = tail;
    }

}

#endif //MONGAN_FLATTEN_LIST_H
