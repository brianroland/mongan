//
// Created by Christopher Roland on 9/30/16.
//
// Found it useful to make decision diagram for each method,
// depending on the values of arguments and state of object --> different types of outcome
//

#ifndef NULL_OR_CYCLE_H
#define NULL_OR_CYCLE_H

#include <functions_and_classes_42/sl_list.h>

template<typename T>
bool DoesContainCycle(const SinglyLinkedList<T> * list) {

    assert(list->head()!=nullptr);

    SingleLinkNode<T> * head = list->head();
    if (head->next()==nullptr) {
        return false;
    }else if (head->next()==head) {
        return true;
    }

    SingleLinkNode<T> * curr1 = list->head();
    SingleLinkNode<T> * curr2 = list->head()->next();

    int iteration = 0;
    while (true) {
        iteration++;

        if (curr2->next()==nullptr) {
            return false;
        } else {
            curr2 = curr2->next();
        }

        if (iteration % 2 == 0) {       //arithmatic ops precede relations
            curr1 = curr1->next();
        }

        if (curr2==curr1) { return true; }
    }


}

#endif //NULL_OR_CYCLE_H
