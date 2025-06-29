#include <stdint.h>
#include <stdio.h>

static void find_value(uint32_t* list, uint32_t target, uint32_t* l, uint32_t* r) {
    if(list == NULL || l == NULL || r == NULL) {
        return;
    }

    uint32_t mid = 0;
    while(*r - *l > 1) {
        mid = *l + (*r - *l) / 2;
        if(list[mid] == target) {
            *l = mid;
            *r = mid;
            break;
        }
        else if(list[mid] > target) {
            *r = mid;
        }
        else {
            *l = mid;
        }
    }
}

int main(void) {
    uint32_t list[10] = {10, 16, 34, 46, 55, 100, 146, 160, 199, 240};
    uint32_t target1 = 100, target2 = 150, target3 = 170;
    uint32_t l = 0, r = 9;
    
    find_value(list, target1, &l, &r);
    printf("target1 is between %d and %d\n", l, r);

    l = 0; r = 9;
    find_value(list, target2, &l, &r);
    printf("target2 is between %d and %d\n", l, r);

    l = 0; r = 9;
    find_value(list, target3, &l, &r);
    printf("target3 is between %d and %d\n", l, r);

    return 0;
}