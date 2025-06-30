#ifndef _STACK_ARRAY_TYPE_
#define _STACK_ARRAY_TYPE_

#include "stack.h"

enum {
    okay,
    malloc_err,
    out_of_boundary_err,
} stack_error_e;

typedef struct stack_config {
    ELEMENT_TYPE *data;
    size_t size;
    size_t capacity;
    size_t write_idx;
} stack_config_t;

bool is_full(stack_config_t* config);

#endif // _STACK_ARRAY_TYPE_