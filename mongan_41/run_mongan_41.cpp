/*
 *  (1) Get something to work
 *  (2) Understand every c++ aspect
 *  (3) install GoogleTest unit-testing framework
 */

#include <iostream>
#include <sstream>
#include <string>
#include "functions_and_classes_41/stack.h"

int main() {
    std::cout << "mongan_41 main(): beg" << std::endl;

    printf("mongan_41 main(): begin test StackNode class\n");
    StackNode<double> * node = new StackNode<double>(new double(3.14), nullptr);
    std::stringstream ss;
    ss << node->get_data();
    printf("%s\n", ss.str().c_str() );
    printf("the data stored in the node is %.2f\n", *node->get_data());
    printf("mongan_41 main(): end test StackNode class\n");

    printf("mongan_41 main(): beg test Stack class\n");
    Stack<double> * stack = new Stack<double>();
    std::stringstream value_of_head;
    value_of_head << stack->get_head();
    printf("before insert %s\n", value_of_head.str().c_str());


    stack->push(new double(6.28));
    stack->push(new double(9.42));
    double top = * stack->top();
    printf("top=%.2f\n", top);


    while (true) {
        if (stack->top()!= nullptr) {
            double popped_top = * stack->pop();
            printf("popped_top=%.2f\n", popped_top);
        } else {
            break;
        }
    }

    value_of_head << stack->get_head();
    printf("after pops, value_of_head=%s\n",value_of_head.str().c_str());

    printf("mongan_41 main(): end test Stack class\n");


    double x = 5.0;
    const double & y = x;
    x=6.0;


    std::cout << "mongan_41 main(): end" << std::endl;
    return 0;
}