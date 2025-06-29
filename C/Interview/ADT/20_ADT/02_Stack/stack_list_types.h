#ifndef _STACK_LIST_TYPE_
#define _STACK_LIST_TYPE_

#include "stack.h"

typedef struct stack_node{
    ELEMENT_TYPE value;
    struct stack_node* next;
} stack_node_t;

typedef struct stack_config
{
    stack_node_t* root;
    size_t capacity;
    size_t size;
} stack_config_t;

#endif //  _STACK_LIST_TYPE_