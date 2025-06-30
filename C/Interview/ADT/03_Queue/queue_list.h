#ifndef _QUEUE_LIST_H_
#define _QUEUE_LIST_H_

#include "queue.h"

#define QUEUE_TYPE int

typedef struct queue_node {
    QUEUE_TYPE data;
    struct queue_node* next;
} queue_node_t;

typedef struct queue_config {
    queue_node_t* node;

} queue_config_t;

#endif // _QUEUE_LIST_H_