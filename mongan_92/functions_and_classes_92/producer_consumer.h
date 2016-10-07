//
// Created by Christopher Roland on 10/7/16.
//

#ifndef MONGAN_PRODUCE_CONSUMER_H
#define MONGAN_PRODUCE_CONSUMER_H


#include <cassert>

using namespace std;

class IntBuffer {
private:
    int size_;
    int* base_;
    int index_;
public:
    IntBuffer(int size=4) : size_(size), index_(0) {
        base_ = new int[size_];
        assert(size_>=1);
    }
    ~IntBuffer() {
        delete[] base_;
    }

    int put(int i) {
        int old_index = index_;
        base_[old_index] = i;
        cout << "IntBuffer instance at " << this << " inserted " << i << " at position " << old_index << endl;
        index_ = (++index_) % size_;
        return(old_index);
    }

    int get(int index) {
        cout << "IntBuffer instance at " << this << " returned " << base_[index] << endl;
        return base_[index];
    }

};

int produce(IntBuffer * b) {

    int i_random = rand() % 10;
    int index = b->put(i_random);
    cout << "producer put random integer " << i_random << " at index " << index << " in buffer at address " << b << endl;
    return index;
}

void consume(IntBuffer *b, int index) {

    int i_out = b->get(index);
    cout << "consumer got integer " << i_out << " at index " << index << " in buffer at address" << b << endl;
}

#endif //MONGAN_PRODUCE_CONSUMER_H
