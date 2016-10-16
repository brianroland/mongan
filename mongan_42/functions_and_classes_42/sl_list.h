//
// Created by Christopher Roland on 10/16/16.
//

#ifndef MONGAN_SL_LIST_H
#define MONGAN_SL_LIST_H

#include <cstdio>
#include <iostream>

template <class T>
class SingleLinkNode {
private:
    const T *data_;             //instructions using data cannot change value at that address
    SingleLinkNode<T> *next_;
public:
    SingleLinkNode(const T *data, SingleLinkNode *next) : data_(data), next_(next) {}
    ~SingleLinkNode() {
        printf("SingleLinkNode:~SingleLinkNode(): beg\n");
        std::cout << "Before delete data=" << *this->data_ << std::endl;
        delete this->data_;              //the node is responsible for the memory at data
        printf("SingleLinkNode:~SingleLinkNode(): end\n");
    }

    SingleLinkNode<T> * next() const {
        return next_;
    }

    void set_next(SingleLinkNode * next) {
        SingleLinkNode::next_ = next;
    }

    const T * data() const {
        return data_;
    }


};

template<class T>
struct FindResult {
    bool found_;
    SingleLinkNode<T> * target_;
    SingleLinkNode<T> * previous_;
    FindResult(bool found, SingleLinkNode<T> * target, SingleLinkNode<T> * previous)
            : found_(found), target_(target), previous_(previous) {}
};

template <class T>
class SinglyLinkedList {
private:
    SingleLinkNode<T> *head_;
    SingleLinkNode<T> *tail_;

public:
    SinglyLinkedList(): head_(nullptr), tail_(nullptr) {}

    bool IsEmpty() const { return head_==nullptr;}
    const T * GetDataAtFront() const {
        if (this->IsEmpty() ){
            return nullptr;
        } else {
            return this->head_->data();
        }
    }

    bool InsertAfter(SingleLinkNode<T> * target, const T * data) {

        //force insert at head
        if (target == nullptr and head_ == nullptr) {
            head_ = new SingleLinkNode<T>(data, nullptr);
            tail_ = head_;
            return true;
        } else if (target == nullptr and head_ != nullptr) {
            head_ = new SingleLinkNode<T>(data, head_);
            return true;
        }

        //target is not nullptr, do not force insert at head, looking for a valid address to insert after
        SingleLinkNode<T> * curr = head_;
        while (true) {
            if (curr==nullptr) {
                return false;
            } else if (curr==target) {
                curr->set_next( new SingleLinkNode<T>(data, curr->next()) );
                if (curr==tail_) {
                    tail_ = curr->next();
                }
                return true;

            } else {
                curr = curr->next();
            }
        }
    }

    bool InsertInFront(const T * data) {
        return InsertAfter(nullptr, data);
    }

    bool Remove(SingleLinkNode<T> * target) {

        if (target==nullptr){
            return false;
        } else if (this->IsEmpty()) {
            return false;
        } else {

            SingleLinkNode<T> * curr = head_;
            SingleLinkNode<T> * prev = head_;

            while (true) {

                if (curr==nullptr) {
                    return (false);

                } else if (curr==target) {

                    if (curr==head_ and curr==tail_) {
                        head_ = nullptr;
                        tail_ = nullptr;
                    } else if (curr==head_ and curr!=tail_) {
                        head_ = curr->next();
                    } else if (curr!=head_ and curr==tail_) {
                        tail_ = prev;
                        prev->set_next(nullptr);
                    } else {
                        prev->set_next(curr->next());
                    }

                    delete curr;
                    curr=nullptr;
                    return(true);

                } else {
                    prev = curr;
                    curr = curr->next();
                }
            }
        }

    }

    FindResult<T> * Find(const T * t) {

        if (t==nullptr ) {
            return new FindResult<T>(false, nullptr, nullptr);
        } else if (this->IsEmpty() ) {
            return new FindResult<T>(false, nullptr, nullptr);
        } else {

            SingleLinkNode<T> * curr = head_;
            SingleLinkNode<T> * prev = nullptr;

            while (true) {

                if (curr==nullptr) {
                    return new FindResult<T>(false, nullptr, nullptr);
                } else if (curr->data()==t) {
                    return new FindResult<T>(true, curr, prev);
                } else {
                    prev = curr;
                    curr = curr->next();
                }
            }
        }
    }

    SingleLinkNode<T> * head() const {
        return head_;
    }

    SingleLinkNode<T> * tail() const {
        return tail_;
    }
};

#endif //MONGAN_SL_LIST_H
