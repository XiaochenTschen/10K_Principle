#include <stdio.h>
#include <stdint.h>

static void print_bit_uint(uint32_t* data) {
    for(int8_t i = 31; i >= 0; --i) {
        if(((*data >> i) & 0x01)> 0) {
            putchar('1');
        }
        else {
            putchar('0');
        }
    }
}

static void swap_bit(uint32_t* data, uint8_t pos0, uint8_t pos1) {
    uint32_t tmp = (*data >> pos0) ^ (*data >> pos1);
    if((tmp & 0x01) == 1) { // different value
        uint32_t mask = (1 << pos0) | (1 << pos1);
        *data ^= mask;
    }
}

static void reverse_bit_uint(uint32_t* data) {
    uint8_t l = 0, r = 31;
    while(l < r) {
        swap_bit(data, l, r);
        ++l;
        --r;
    }
}

int main(void) {
    uint32_t test_val = 0b100100111100;
    printf("before reverse: ");
    print_bit_uint(&test_val);
    putchar('\n');
    reverse_bit_uint(&test_val);
    printf("after reverse : ");
    print_bit_uint(&test_val);
    putchar('\n');

    return 0;
}