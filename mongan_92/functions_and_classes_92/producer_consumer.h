//
// Created by Christopher Roland on 10/7/16.
//

#ifndef MONGAN_PRODUCE_CONSUMER_H
#define MONGAN_PRODUCE_CONSUMER_H

#include <ctime>
#include <cassert>
#include <chrono>

using namespace std;

class IntBuffer {
private:
    int size_;
    int* base_;
    int index_;

public:
    IntBuffer(int size=4) : size_(size), index_(0), count_(0) {
        base_ = new int[size_];
        assert(size_>=1);
    }
    ~IntBuffer() {
        delete[] base_;
    }

    void put(int i) {

        base_[index_] = i;
        cout << "IntBuffer instance at " << this << " inserted " << i << " at position " << index_ << endl;
    }

    int get() {
        int value = base_[index_];
        index_ = (++index_) % size_;
        count_++;
        cout << "IntBuffer instance at " << this << " returned " << value << endl;
        return value;
    }

    mutex mutex_;
    condition_variable cond_;
    int count_;
};

void producer_onetime(IntBuffer & b) {
    unique_lock<mutex> lck(b.mutex_);       //create lock on mutex, immediately close the lock
    //lck.lock();                             //close lock on mutex

    int i_random = rand() % 10;
    b.put(i_random);
    cout << "producer put random integer " << i_random << " in buffer at address " << &b << endl;
    lck.unlock();                           //open lock on mutex
    b.cond_.notify_one();                   //signal the cv
}

void consumer_onetime(IntBuffer & b) {
    unique_lock<mutex> lck(b.mutex_);               //create a lock on the mutex, do not apply it
    b.cond_.wait(lck);                              //when cv triggers, then lock the mutex

    int i_out = b.get();
    cout << "consumer got integer " << i_out << " in buffer at address" << &b << endl;

    lck.unlock();
}

void print_time() {

    time_t t0 = time(0);
    cout << ctime(& t0) << endl;
}

void print_doubles(vector<double> & vec) {
    for (auto x : vec) {
        cout << x << endl;
    }
}

#endif //MONGAN_PRODUCE_CONSUMER_H
