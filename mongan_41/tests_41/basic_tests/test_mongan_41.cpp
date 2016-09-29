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