//
// Created by Christopher Roland on 10/2/16.
//
#include <iostream>
#include<string>
#include <unordered_map>

using namespace std;

char FirstNonrepeat(const string & s) {
    //Theta(n) touches each datum once

    unordered_map<char, int> num;

    for (auto & x : s) {
        if (num.count(x)==0) {
            num.insert(make_pair(x, 1));
        } else {
            num.at(x) += 1;
        }
        cout << "char=" << x << ", num=" << num.at(x) <<  endl;
    }

    for (auto & x : s) { if (num.at(x)==1) { return x; } }

    return '\0';
}