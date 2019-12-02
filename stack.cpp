#include <iostream>
#include "node.h"
#include "stack.h"


template <class T>
stack<T>::stack(int _max_stack_depth)
{
    stack_max = _max_stack_depth;
    error_node = new node<T>(0);
    stack_depth = 0;
}

template <class T>
STACK_ERROR stack<T>::push(node<T> * x) 
{
    if (stack_depth >= stack_max)
        return STACK_OVERFLOW;
    stack_nodes[stack_depth++] = x;
    return STACK_SUCCESS;
}

template <typename T>
node<T> * stack<T>::pop(STACK_ERROR *p_err)
{
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
}
template <typename T>
bool stack<T>::is_empty(void)
{
    return (stack_depth == 0);
}


        
