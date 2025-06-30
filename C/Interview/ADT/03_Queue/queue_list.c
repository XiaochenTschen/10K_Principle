#include "queue_list.h"

static queue_config_t config = {
    .node = NULL
};

void push(queue_config_t* config, QUEUE_TYPE value){
    queue_node_t* iterator;
    queue_node_t* new_node = (queue_node_t*)malloc(sizeof(queue_node_t));
    new_node->data = value;
    new_node->next = NULL;
    if(is_empty(config)) {
        config->node = new_node;
    }
    else {
        iterator = config->node;
        while(iterator->next) {
            iterator = iterator->next;
        }
        iterator->next = new_node;
    }
}

void pop(queue_config_t* config){
    // delete the first node
    queue_node_t* first_node = config->node;
    if(first_node) {
        config->node = first_node->next;
        free(first_node);
        first_node = NULL;
    }
}

QUEUE_TYPE front(queue_config_t* config){
    if(config->node) {
        return config->node->data;
    }
    else {
        return 0;
    }
}


bool is_empty(queue_config_t* config){
    return config->node == NULL;
}

bool is_full(queue_config_t* config){
    (void) config;
    return false;
}

int main(void) {

    return 0;
}