#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define HEAP_MAX_SIZE  100
#define ALIGNMENT_BYTES 16
#define ADJUST_HEAP_SIZE ( (HEAP_MAX_SIZE) - (ALIGNMENT_BYTES) )
#define ALIGNMENT_MASK  ( ~( (size_t)( ALIGNMENT_BYTES - 1 ) ) )
#define ALIGNED_ADDRESS(addr) (((addr) + ALIGNMENT_BYTES - 1) & ALIGNMENT_MASK)

/* MSB of block_size is used to indicate if the block is free or assigned to application or kernel */
#define BLOCK_SIZE_MASK     ( (size_t)( 1 << ( sizeof(size_t) ) * 8 ) )
#define BLOCK_SIZE(p_block) ( (p_block->block_size) & (~BLOCK_SIZE_MASK) )
#define BLOCK_ALLOCT(p_block) ( (p_block->block_size) |= BLOCK_SIZE_MASK )
#define BLOCK_FREE(p_block) ((p_block->block_size) &= (~BLOCK_SIZE_MASK))

typedef struct heap_block {
    struct heap_block* next_free_block;
    size_t block_size;
} heap_block_t;

static heap_block_t start_block = {
    .next_free_block = NULL,
    .block_size = 0
};
static heap_block_t end_block = {
    .next_free_block = NULL,
    .block_size = HEAP_MAX_SIZE
};

static size_t heap_block_size = sizeof(heap_block_t);
static uint8_t heap[HEAP_MAX_SIZE];
static size_t heap_remaining_size = ADJUST_HEAP_SIZE; // several bytes may be lost
static bool is_heap_initialized = false;

static void heap_initialize(void);
static void insert_new_block_in_list(heap_block_t* p_new_block);

void* port_malloc(size_t required_size) {
    heap_block_t* p_block;
    heap_block_t* p_previous_block;
    heap_block_t* p_new_block;

    size_t extra_block_size = 0;

    void* p_return;

    if(required_size == 0)  return NULL;

    /* calculate the block size */
    required_size += heap_block_size;

    /* block size alignment */
    required_size = (required_size + ALIGNMENT_BYTES - 1) & ALIGNMENT_MASK;

    if(required_size > heap_remaining_size) return NULL;

    {
        
        if(is_heap_initialized == false) {
            heap_initialize();
        }
        /* get the first block meets the required size */
        p_previous_block = &start_block;
        p_block = start_block.next_free_block;
        while(p_block->next_free_block != NULL) { /* not the end_block */
            if(p_block->block_size >= required_size) { /* find the first match block */
                p_return = (void*)((uint8_t*)p_block + heap_block_size);
                /* remove the current block from list */
                p_previous_block->next_free_block = p_block->next_free_block;
                heap_remaining_size -= required_size;

                /* check if this block can be divided into two blocks */
                extra_block_size = p_block->block_size - required_size;
                if(extra_block_size >= 2*heap_block_size) {
                    p_block->block_size = required_size;
                    p_new_block = (heap_block_t*)((uint8_t*)p_block + required_size);
                    p_new_block->block_size = extra_block_size;
                    insert_new_block_in_list(p_new_block);
                }
                BLOCK_ALLOCT(p_block);
                break;
            }
            p_previous_block = p_block;
            p_block = p_block->next_free_block;
        }

    }
    return p_return;
}

void port_free(void* ptr) {
    heap_block_t* p_block = (heap_block_t*)ptr - heap_block_size;
    BLOCK_FREE(p_block);
    memset((uint8_t*)ptr, 0, p->block_size - heap_block_size);
    insert_new_block_in_list(p);
}

static void heap_initialize(void) {
    is_heap_initialized = true;
    /* get the aligned start address */
    size_t start_addr = ALIGNED_ADDRESS( (size_t)&heap[0] );
    
    /* initialize the first free block from this address */
    heap_block_t* first_free_block = (heap_block_t*)start_addr;
    start_block.next_free_block = first_free_block;
    first_free_block->next_free_block = &end_block;
    first_free_block->block_size = ADJUST_HEAP_SIZE;
}

static void insert_new_block_in_list(heap_block_t* p_new_block) {
    heap_block_t* iterator = start_block.next_free_block;
    heap_block_t* p_previous_block = &start_block;
    for(; iterator != NULL && iterator->block_size < p_new_block->block_size; iterator = iterator->next_free_block) {
        p_previous_block = iterator;
    }
    p_previous_block->next_free_block = p_new_block;
    p_new_block->next_free_block = iterator;    
}