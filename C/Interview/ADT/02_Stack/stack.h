#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stddef.h>

#define ELEMENT_TYPE int
#define INIT_SIZE  7

typedef struct stack_config stack_config_t;

stack_config_t* get_stack_config_pointer(void);
int stack_init(stack_config_t* config);
int push(stack_config_t* config, ELEMENT_TYPE element);
void pop(stack_config_t* config);
ELEMENT_TYPE top(stack_config_t* config);
bool is_empty(stack_config_t* config);

#else
#endif