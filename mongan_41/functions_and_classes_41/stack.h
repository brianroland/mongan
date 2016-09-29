//
// Created by Christopher Roland on 9/28/16.
//
// an argument that is a const pointer --> the function cannot change the object referenced by the pointer
// const pointer means pointer to const

#ifndef MONGAN_41_STACK_H
#define MONGAN_41_STACK_H

template <class T>
class StackNode {
private:
    StackNode<T> * next;
    const T * data;       //holds the address of a const object, the object cannot be overwritten
public:
    StackNode(const T * data_, StackNode<T> * next_): data(data_), next(next_) {}
    const T * get_data() const { return data;}          //returns the address of a const object
    StackNode<T> * get_next() const { return next; }    //method does not change the state of the object
};


template <class T>
class Stack {
private:
    StackNode<T> * head;
public:
    Stack(): head(nullptr) {}
    ~Stack() {}
    //ToDo: write destructor -> if an address is in the stack when the stack is destroyed, the object at that address
    //should be destroyed


    void push(const T * t) {
        this->head = new StackNode<T>(t, this->head);
    }

    const T * pop() {

        if (this->head == nullptr) {
            return nullptr;
        } else {
            //at least 1 node in stack
            StackNode<T> * old_head = this->head;

            this->head = old_head->get_next();          //possibly null
            return old_head->get_data();
        }

    }

    const T * top() const {
        if (!this->is_empty()) {
            return this->head->get_data();
        } else {
            return nullptr;
        }
    }

    bool is_empty() const {
        return !this->head;
    }

    StackNode<T> * get_head() { return this->head; }

};

#endif //MONGAN_41_STACK_H
