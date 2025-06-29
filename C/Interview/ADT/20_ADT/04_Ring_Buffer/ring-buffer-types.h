#ifndef _RING_BUFFER_TYPES_
#define _RING_BUFFER_TYPES_

#include <stddef.h>
#include <stdbool.h>

#define ELEMENT_TYPE int

typedef enum buffer_state{
    buffer_okay,
    buffer_overflow,
    buffer_malloc_error
}buffer_state_e;

typedef struct ring_buffer {
    ELEMENT_TYPE* data;
    int r_index;
    int w_index;
    bool full;
} ring_buffer_t;

typedef struct ring_buffer_config {
    ring_buffer_t* buffer;
    size_t size;
    bool overwrite_allowed;
} ring_buffer_config_t;

int ring_buffer_init(ring_buffer_config_t* config);
bool is_empty(ring_buffer_config_t* config);
bool is_full(ring_buffer_config_t* config);
int write_buffer(ring_buffer_config_t* config, ELEMENT_TYPE value);
ELEMENT_TYPE read_buffer(ring_buffer_config_t* config);

#endif //_RING_BUFFER_TYPES_