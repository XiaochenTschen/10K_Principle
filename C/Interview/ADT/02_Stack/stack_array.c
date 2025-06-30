#include "stack.h"
#include "stack_array_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static stack_config_t stack_config = {
    .data = NULL,
    .capacity = INIT_SIZE,
    .size = 0,
    .write_idx = 0
};

stack_config_t* get_stack_config_pointer(void) {
    return &stack_config;
}

int stack_init(stack_config_t* config) {
    ELEMENT_TYPE* data = (ELEMENT_TYPE*)malloc(INIT_SIZE*sizeof(ELEMENT_TYPE));
    if(data == NULL) {
        return malloc_err;
    }
    config->data = data;
    return okay;
}

int push(stack_config_t* config, ELEMENT_TYPE element) {
    // check if stack is full
    if(is_full(config)) {
        config->data = (ELEMENT_TYPE*)realloc(config->data, 2*config->capacity*sizeof(ELEMENT_TYPE));
        if(config->data == NULL) {
            return malloc_err;
        }
        config->capacity *= 2;
    }

    config->data[config->write_idx] = element;
    ++config->write_idx;
    ++config->size;
    return okay;
}

void pop(stack_config_t* config) {
    // check if stack is empty
    if(is_empty(config)) {
        return;
    }

    --config->write_idx;
    --config->size;

    // check if extra space should be freed
    if(config->size*2 < config->capacity && config->capacity > INIT_SIZE) {
        size_t new_capacity = config->capacity >> 1;
        config->data = (ELEMENT_TYPE*)realloc(config->data, new_capacity*sizeof(ELEMENT_TYPE));
        if(config->data) {
            config->capacity = new_capacity;
        }
    }
}

ELEMENT_TYPE top(stack_config_t* config) {
    // can only be used after empty check
    return config->data[config->write_idx-1];
}

bool is_full(stack_config_t* config) {
    return config->write_idx >= config->capacity;
}

bool is_empty(stack_config_t* config) {
    return config->write_idx == 0;
}

int main(void) {
    stack_config_t* config = get_stack_config_pointer();
    stack_init(config);

    for(int i = 0; i < 10; ++i) {
        push(config, i*2);
    }
    printf("capacity of stack: %zu\n", config->capacity);
    printf("size of stack: %zu\n", config->size);
    printf("top element: %d\n", top(config));

    printf("pop elements from stack: ");
    for(int i = 0; i < 5; ++i) {
        ELEMENT_TYPE tmp = top(config);
        pop(config);
        printf("%d ", tmp);
    }
    putchar('\n');
    printf("capacity of stack: %zu\n", config->capacity);
    printf("size of stack: %zu\n", config->size);
    printf("top element: %d\n", top(config));

    printf("pop elements from stack: ");
    while(!is_empty(config)) {
        ELEMENT_TYPE tmp = top(config);
        pop(config);
        printf("%d ", tmp);
    }
    putchar('\n');
    printf("capacity of stack: %zu\n", config->capacity);
    printf("size of stack: %zu\n", config->size);
    printf("write index: %zu\n", config->write_idx);

    return 0;
}
