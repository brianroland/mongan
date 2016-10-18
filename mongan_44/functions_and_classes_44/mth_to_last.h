//
// Created by Christopher Roland on 10/17/16.
//

#ifndef MONGAN_MTH_TO_LAST_H
#define MONGAN_MTH_TO_LAST_H

#include <forward_list>
#include <cassert>
#include <iterator>
#include <functions_and_classes_42/sl_list.h>

using namespace std;


bool MthToLast(forward_list<double> & list,  int m, double & out) {

    assert(!list.empty());

    forward_list<double>::iterator current   = list.begin();
    forward_list<double>::iterator next      = ++list.begin();
    forward_list<double>::iterator trailer   = list.begin();

    int current_position=0;
    int trailer_position=0;

    while ( next != list.end() ) {           //proxy for current->next=null

        if ((current_position - trailer_position) == m) {
            ++trailer;
            trailer_position++;
        }

        ++current;
        current_position++;
        ++next;
    }

    if ((current_position - trailer_position)==m) {
        out = *trailer;
        return true;
    } else {
        return false;
    }
};

#endif //MONGAN_MTH_TO_LAST_H
