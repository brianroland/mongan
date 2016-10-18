//
// Created by Christopher Roland on 10/17/16.
//


#include <iostream>
#include "gtest/gtest.h"
#include <forward_list>
#include "mth_to_last.h"

using namespace std;

TEST(test_hello_world_0, test_hello_world) {

    printf("\ntest_hello_world_0: beg\n");

    printf("test_hello_world_0: end \n");
}

TEST(test_forward_list_0, test_forward_list) {

    printf("\ntest_forward_list_0: beg\n");

    forward_list<double> x;
    x.push_front(2.2);      //m=0
    x.push_front(1.1);      //m=1
    x.push_front(0.0);      //m=2

    for (forward_list<double>::iterator a=x.begin(); a!=x.end(); ++a) { cout << *a << endl; }

    for (auto a : x) { cout << a << endl; }

    printf("test_forward_list_0: end \n");
}


TEST(test_short_list_0, test_short_list) {

    printf("\ntest_short_list_0: beg\n");

    int m = 3;
    double out = -1;
    forward_list<double> list;
    list.push_front(1.1);
    bool success = MthToLast(list, m, out);

    cout << "success=" << success << ", and out=" << out << endl;

    printf("test_short_list_0: end\n");
}

TEST(test_long_list_1, test_long_list) {

    printf("\ntest_long_list_1: beg\n");

    int m = 3;
    double out = -1;
    forward_list<double> list;
    list.push_front(4.4);   //m=0               insert first, this ends up at the back
    list.push_front(3.3);   //m=1
    list.push_front(2.2);   //m=2
    list.push_front(1.1);   //m=3
    list.push_front(0.0);   //m=4
    bool success = MthToLast(list, m, out);

    cout << "success=" << success << ", and out=" << out << endl;

    ASSERT_EQ(out, 1.1);

    printf("test_long_list_1: end\n");
}