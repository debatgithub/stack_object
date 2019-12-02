#include <iostream>
#include "stack.h"
int main (void );
#define STACK_MAX 8
int stack_vals[STACK_MAX+1] = { 0, 1, 2, 3, 5, 8, 13, 21, 34 };
int main (void ) 
{

    stack<int> * p_test_stack = new stack<int>(STACK_MAX);
    STACK_ERROR res = STACK_SUCCESS;
    node<int> * p_node = NULL;
    if (p_test_stack == NULL) {
        std::cout << "Stack constructor failed" << std::endl;
        return 1;
    }
    std::cout << "Stack constructor passed" << std::endl;
 
    for (int i = 0; i < STACK_MAX; i++) {
        p_node = new node<int>(stack_vals[i]);
        res = p_test_stack->push(p_node);
        if (res != STACK_SUCCESS) {
            std::cout << "Stack push normal test failed" << std::endl;
            return 1;
        }
    }
    std::cout << "Stack push normal test passed" << std::endl;
    p_node = new node<int>(stack_vals[STACK_MAX]);
    res = p_test_stack->push(p_node);
    if (res != STACK_OVERFLOW) {
        std::cout << "Stack push overflow test failed" << std::endl;
        return 1;
    }
    std::cout << "Stack push overflow test passed" << std::endl;
    for (int i = 0; i < STACK_MAX; i++) {
        p_node = p_test_stack->pop(&res);
        if (res != STACK_SUCCESS) {
            std::cout << "Stack pop normal test failed" << std::endl;
            return 1;
        }
        int x = p_node->get_data();
        if (x != (stack_vals[STACK_MAX -i -1])) {
            std::cout << "Stack pop integrity test failed" << std::endl;
            std::cout << "Expected value is " << stack_vals[STACK_MAX -i -1] << std::endl;
            std::cout << "Actual popped value is " << x << std::endl;
        }
    }
    std::cout << "Stack pop normal test passed" << std::endl;
    p_node = p_test_stack->pop(&res);
    if (res != STACK_UNDERFLOW) {
        std::cout << "Stack pop underflow test failed" << std::endl;
        return 1;
    }
    std::cout << "Stack pop underflow test passed" << std::endl;
    delete p_test_stack;
    return 0;

   
}

        
