#include "ring-buffer-types.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE  8
#define INDEX_MASK  (BUFFER_SIZE-1) // in order to use mask, BUFFER_SIZE should be power of 2

static char data[BUFFER_SIZE*sizeof(ELEMENT_TYPE)];
static ring_buffer_t buffer = {
    .data = (ELEMENT_TYPE*)data,
    .r_index = 0,
    .w_index = 0,
    .full = false
};

static ring_buffer_config_t buffer_config = {
    .buffer = &buffer,
    .size = 0,
    .overwrite_allowed = true
};

static ring_buffer_config_t* get_config_instance() {
    return &buffer_config;
}

int ring_buffer_init(ring_buffer_config_t* config) {
    memset(config->buffer->data, 0, sizeof(data)); 
    return buffer_okay;
}

bool is_empty(ring_buffer_config_t* config) {
    return (config->buffer->r_index == config->buffer->w_index) && (!config->buffer->full);
}

bool is_full(ring_buffer_config_t* config) {
    return config->buffer->full;
}

int write_buffer(ring_buffer_config_t* config, ELEMENT_TYPE value) {
    if(is_full(config)) {
        if(config->overwrite_allowed) {
            config->buffer->data[config->buffer->w_index] = value;
            ++config->buffer->w_index;
            config->buffer->w_index &= INDEX_MASK;
            ++config->buffer->r_index;
            config->buffer->r_index &= INDEX_MASK;
        }
        else {
            return buffer_overflow;
        }
    }
    else {
        config->buffer->data[config->buffer->w_index] = value;
        ++config->buffer->w_index;
        config->buffer->w_index &= INDEX_MASK;
        if(config->buffer->w_index == config->buffer->r_index) {
            config->buffer->full = true;
        }
    }
    return buffer_okay;
}

// function should be used after empty check
ELEMENT_TYPE read_buffer(ring_buffer_config_t* config) {
    ELEMENT_TYPE value = config->buffer->data[config->buffer->r_index];
    ++config->buffer->r_index;
    config->buffer->r_index &= INDEX_MASK;
    config->buffer->full = false;
    return value;
}

int main(void) {
    ring_buffer_config_t* config = get_config_instance();

    for(int i = 0; i < BUFFER_SIZE; ++i) {
        write_buffer(config, i*2);
    }
    // buffer should be full now
    printf("buffer read idx: %d\n", config->buffer->r_index);
    printf("buffer write idx: %d\n", config->buffer->w_index);
    if(is_full(config)) {
        printf("buffer is full\n");
    }
    buffer_state_e state = write_buffer(config, 9);
    if(state == buffer_overflow) {
        printf("buffer overflowed\n");
    }

    printf("read elements from buffer: ");
    while(!is_empty(config)) {
        ELEMENT_TYPE val = read_buffer(config);
        printf("%d ", val);
    }
    putchar('\n');
    printf("buffer read idx: %d\n", config->buffer->r_index);
    printf("buffer write idx: %d\n", config->buffer->w_index);

    return 0;
}

