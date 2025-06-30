#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_TYPE int
typedef struct queue_config queue_config_t;

void push(queue_config_t* config, QUEUE_TYPE value);
void pop(queue_config_t* config);
QUEUE_TYPE front(queue_config_t* config);

bool is_empty(queue_config_t* config);
bool is_full(queue_config_t* config);

#endif

