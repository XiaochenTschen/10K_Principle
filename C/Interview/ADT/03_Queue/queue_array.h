#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H

#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    QUEUE_TYPE* data;
    size_t capacity;
    size_t size;
    size_t r_index;
    size_t w_index;
    size_t index_mask;
    bool is_empty;
    bool is_full;
} queue_t;

typedef struct queue_config {
    queue_t* queue;
    bool overflow_allowed;
} queue_config_t;

#define DECLARE_QUEUE(q_size,q_overflow_allowed)               \
    static QUEUE_TYPE queue_array[q_size];                     \
    static queue_t queue = {                                   \
        .data = &queue_array[0],                               \
        .capacity = q_size,                                    \
        .size = 0,                                             \
        .r_index = 0,                                          \
        .w_index = 0,                                          \
        .index_mask = q_size - 1,                              \
        .is_empty = true,                                      \
        .is_full = false                                       \
    };                                                         \
    static queue_config_t config = {                           \
        .queue = &queue,                                       \
        .overflow_allowed = q_overflow_allowed                 \
    }

#endif // _QUEUE_ARRAY_H