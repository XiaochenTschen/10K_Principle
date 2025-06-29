#include<stdio.h>
#include "queue_array.h"
#include<assert.h>

#define QUEUE_SIZE          8 
#define OVER_FLOW_ALLOWED   false 

DECLARE_QUEUE(QUEUE_SIZE, OVER_FLOW_ALLOWED);

void push(queue_config_t* config, QUEUE_TYPE value){
    if(is_full(config)) {
        if(config->overflow_allowed) {
            config->queue->data[config->queue->w_index] = value;
            ++config->queue->w_index;
            config->queue->w_index &= config->queue->index_mask;
            config->queue->r_index = config->queue->w_index;
        }
        else {
            // return queue_overflow;
        }
    }
    else {
        config->queue->is_empty = false;
        config->queue->data[config->queue->w_index] = value;
        ++config->queue->w_index;
        config->queue->w_index &= config->queue->index_mask;
        if(config->queue->w_index == config->queue->r_index) {
            config->queue->is_full = true;
        }
    }
}

void pop(queue_config_t* config) {
    if(!is_empty(config)) {
        ++config->queue->r_index;
        config->queue->r_index &= config->queue->index_mask;
        config->queue->is_full = false;
        if(config->queue->r_index == config->queue->w_index) {
            config->queue->is_empty = true;
        }
    }
}

// this function can be used only if the queue is not empty
QUEUE_TYPE front(queue_config_t* config){
    return config->queue->data[config->queue->r_index];
}


bool is_empty(queue_config_t* config){
    return config->queue->is_empty;
}

bool is_full(queue_config_t* config){
    return config->queue->is_full;
}

int main(void) {
    queue_config_t* q_config = &config;
    return 0;
}
