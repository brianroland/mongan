//
// Created by Christopher Roland on 10/2/16.
//
#include <iostream>
#include <string>
#include <unordered_set>
#include "remove_characters.h"

using namespace std;

void RemoveCharacters(string * target, const string * remove) {

    unordered_set<char> chars_to_remove;
    for (auto & x : *remove) { chars_to_remove.insert(x); }

    int count_writes = 0;
    for (auto & x : *target) {
        if (chars_to_remove.count(x)==0) {
            (*target)[count_writes++] = x;
        }
    }
    target->resize(count_writes);

}
