//
// Created by Christopher Roland on 10/7/16.
//

#ifndef MONGAN_PRODUCE_CONSUMER_H
#define MONGAN_PRODUCE_CONSUMER_H

#include <ctime>
#include <cassert>
#include <chrono>

using namespace std;

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
