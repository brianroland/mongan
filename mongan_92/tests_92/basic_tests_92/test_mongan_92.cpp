

#include <thread>
#include "gtest/gtest.h"
#include "producer_consumer.h"

TEST(test_hello_world, test_hello_world) {
    printf("\ntest_hello_world: beg\n");
    printf("test_hello_world: end\n");
}

TEST (print_time, print_time) {
    printf("\nprint_time: beg\n");
    thread t1(print_time);
    thread t2(print_time);

    t1.join();
    t2.join();
    printf("print_time: end\n");
}

TEST (print_double, print_doubles) {
    printf("\nprint_doubles: beg\n");
    vector<double> x = {1,3,5};
    vector<double> y = {2,4,6};

    thread tx (print_doubles, ref(x));
    thread ty (print_doubles, ref(y));

    tx.join();
    ty.join();

    printf("print_doubles: end\n");
}

TEST(test_producer_consumer_1, test_producer_consumer) {
    printf("\ntest_producer_consumer_1: beg\n");
    printf("test_producer_consumer_1: end\n");
}



