#ifndef __INCLUDE_STACK_H__
#define __INCLUDE_STACK_H__
#include <iostream>
typedef enum estack_error { STACK_UNDERFLOW = -2, STACK_OVERFLOW = -1, STACK_SUCCESS = 0 } STACK_ERROR;
#include "node.h"
template <typename T>
class stack {
    public:
       stack<T>(int _max_stack_depth ) {
           stack_max = _max_stack_depth;
           error_node = new node<T>(0);
           stack_depth = 0;
        };
        ~stack<T>() { delete error_node; };
        STACK_ERROR push(node<T> *x) {
            if (stack_depth >= stack_max)
                return STACK_OVERFLOW;
            stack_nodes[stack_depth++] = x;
            return STACK_SUCCESS;
        };
        node<T> * pop(STACK_ERROR * p_err) {
            if (stack_depth < 0) { 
                if (p_err != NULL)  
                    *p_err = STACK_UNDERFLOW;
                 return error_node;
             }
            else {
                if (p_err != NULL)
                    *p_err = STACK_SUCCESS;
                return (stack_nodes[--stack_depth]);
            }
        };
        bool is_empty() {
            return (stack_depth == 0);
        };
    protected:
        int stack_depth;
        int stack_max;
        node<T> * stack_nodes[256];
        node<T> * error_node;
 
};
#endif // __INCLUDE_STACK_H__


         
