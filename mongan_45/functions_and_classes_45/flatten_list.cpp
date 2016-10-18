//
// Created by Christopher Roland on 10/17/16.
//


#include <cassert>
#include <stack>
#include "flatten_list.h"

using namespace std;

void Flatten(Node * head) {

    assert(head!=nullptr);

    stack<Node*> current_node;
    stack<Node*> parent_of_current_list;
    stack<Node*> head_of_current_list;

    current_node.push(head);
    head_of_current_list.push(head);
    parent_of_current_list.push(nullptr);

    while (!current_node.empty()) {

        Node * curr = current_node.top();
        current_node.pop();

        int count = 0;
        if (curr->next_ != nullptr) {
            current_node.push(curr->next_);
            count++;
        }

        if (curr->child_ != nullptr) {
            current_node.push(curr->child_);
            head_of_current_list.push(curr->child_);
            parent_of_current_list.push(curr);
            count++;
        }

        if (count == 0 and parent_of_current_list.top() != nullptr) {

            Node * parent = parent_of_current_list.top();
            Node * head = head_of_current_list.top();

            parent_of_current_list.pop();
            head_of_current_list.pop();

            Insert(head, curr, parent);
            parent->child_ = nullptr;

            if (parent->next_ == nullptr) {
                current_node.push(curr);
            }
        }
    }
}

void PrintValues(Node * head) {
    assert(head!=nullptr);
    Node * curr=head;
    while(curr!=nullptr) {
        cout << curr->value_ << endl;
        curr = curr->next_;
    }
}

void Connect(Node * left, Node * right) {

    left->next_ = right;
    right->prev_ = left;
}

void Insert(Node * head, Node * tail, Node * target) {
    //insert list between tail and tail->next, O(1) operation

    assert(head!=nullptr);
    assert(tail!=nullptr);
    assert(target!=nullptr);

    if (target->next_ != nullptr) {
        tail->next_ = target->next_;
        target->next_->prev_ = tail;
    }

    target->next_ = head;
    head->prev_ = target;



}

