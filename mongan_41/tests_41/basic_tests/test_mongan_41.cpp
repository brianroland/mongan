//
// Created by Christopher Roland on 9/29/16.
//

#include "gtest/gtest.h"
#include "stack.h"


TEST(test_mongan_41, test_new_stack_is_empty) {
    printf("\ntest_new_stack_is_empty: beg\n");
    Stack<double> * stack = new Stack<double>();
    printf("is_empty=%d\n", stack->is_empty());
    ASSERT_EQ(stack->is_empty(), true);
    printf("test_new_statck_is_empty: end\n");
}

TEST(test_mongan_41, test_top) {
    printf("\ntest_top: beg\n");
    Stack<double> * stack = new Stack<double>();
    stack->push(new double(1.23));
    ASSERT_EQ(*stack->top(), 1.23);
    printf("test_top: end\n");
}

TEST(test_mongan_41, test_destructor) {
    printf("\ntest_destructor: beg\n");
    Stack<double> * stack = new Stack<double>;
    stack->push(new double(1.23));
    stack->push(new double(2.34));
    delete stack;
    stack = nullptr;

    //TODO: how to verify that memory allocated to these objects is returned to the OS?

    printf("test_destructor: so this verifies that calling the destructor does not cause an exception\n");
    printf("test_destructor: end\n");
}
