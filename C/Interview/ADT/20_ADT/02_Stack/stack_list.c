#include "stack.h"
#include "stack_list_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static stack_config_t config = {
    .root = NULL,
    .capacity = 0xffffffff,
    .size = 0
};

stack_config_t* get_stack_config_pointer(void) {
    return &config;
}

int stack_init(stack_config_t* config) {
    return 0;
}

int push(stack_config_t* config, ELEMENT_TYPE element)
{
    stack_node_t* new_node = (stack_node_t*)malloc(sizeof(stack_node_t));
    assert(new_node != NULL);
    new_node->value = element;
    new_node->next = config->root;
    config->root = new_node;
    ++config->size;

    return 0;
}

void pop(stack_config_t* config)
{
    if(!is_empty(config)) {
        stack_node_t* top_node = config->root;
        config->root = top_node->next;
        free(top_node);
        --config->size;
    }
}

ELEMENT_TYPE top(stack_config_t* config)
{
    assert(is_empty(config) == false);
    return config->root->value;
}

bool is_empty(stack_config_t* config)
{
    return config->root == NULL;
}

int main()
{    
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

    return 0;
}