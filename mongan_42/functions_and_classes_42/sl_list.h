//
// Created by Christopher Roland on 9/30/16.
//

#ifndef MONGAN_SL_LIST_H
#define MONGAN_SL_LIST_H

template <class T>
class SingleLinkNode {
private:
    const T *data;             //instructions using data cannot change value at that address
    SingleLinkNode<T> *next;
public:
    SingleLinkNode(const T *data_, SingleLinkNode *next_) : data(data_), next(next_) {}
    ~SingleLinkNode() {
        printf("SingleLinkNode:~SingleLinkNode(): beg\n");
        delete this->data;              //the node is responsible for the memory at data
        printf("SingleLinkNode:~SingleLinkNode(): end\n");
    }

    SingleLinkNode *getNext() const {
        return next;
    }

    void setNext(SingleLinkNode *next) {
        SingleLinkNode::next = next;
    }

    const T *getData() const {
        return data;
    }
};

template <class T>
class SinglyLinkedList {
private:
    SingleLinkNode<T> *head;
    SingleLinkNode<T> *tail;

public:
    SinglyLinkedList(): head(nullptr), tail(nullptr) {}

    bool isEmpty() { return head==nullptr;}
    const T * front(){
        if (this->isEmpty() ){
            return nullptr;
        } else {
            return this->head->getData();
        }
    }

    bool insertAfter(SingleLinkNode<T> * target, const T *data) {

        //insert at head
        if (target==nullptr and head==nullptr) {
            head = new SingleLinkNode<T>(data, nullptr);
            tail = head;
            return true;
        } else if (target==nullptr and head!=nullptr) {
            head = new SingleLinkNode<T>(data, head->getNext());
            return true;
        }

        //insert not at head
        SingleLinkNode<T> * curr = head;
        while (true) {
            if (curr==target) {
                target->setNext( new SingleLinkNode<T>(data, target->getNext()) );
                if (target==tail) {
                    tail = target->getNext();
                }
                return true;
            } else if (curr==nullptr) {
                return false;
            }else {
                curr = curr->getNext();
            }
        }
    }



};


#endif //MONGAN_SL_LIST_H
