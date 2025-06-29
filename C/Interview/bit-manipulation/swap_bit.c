#include <stdint.h>
#include <stdio.h>

static void print_byte_in_bits(uint8_t* byte) {
    for(int8_t bit_pos = 7; bit_pos >= 0; --bit_pos) {
        if(((*byte)&(1<<bit_pos)) == 0) {
            putchar('0');
        }
        else {
            putchar('1');
        }
    }
}

static void swap_bit_in_byte(uint8_t* byte, uint8_t bit_pos_0, uint8_t bit_pos_1) {
    if(byte == NULL || bit_pos_0 >= 8 || bit_pos_1 >= 8) {
        return;
    }
    if(bit_pos_0 == bit_pos_1) {
        return;
    }

    // check if the values of these two bits are the same
    uint8_t temp = (*byte >> bit_pos_0) ^ (*byte >> bit_pos_1);

    if(temp&1 == 1) { // bit values are different
        uint8_t mask = (1 << bit_pos_0) | (1 << bit_pos_1);
        *byte ^= mask;
    }
}

int main() {
    uint8_t test_val = 0b11001100;
    uint8_t bit_pos_0 = 0, bit_pos_1 = 3;
    printf("before swap: ");
    print_byte_in_bits(&test_val);
    putchar('\n');
    swap_bit_in_byte(&test_val, bit_pos_0, bit_pos_1);
    printf("after swap : ");
    print_byte_in_bits(&test_val);
    putchar('\n');
}