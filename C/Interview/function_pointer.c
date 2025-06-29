#include <stdint.h>
#include <stdio.h>

typedef int (*fp_t)(int, int);

static int sum(int a, int b) {
    return a+b;
}

int main(void) {
    fp_t fp;
    fp = sum;
    int res = fp(2, 3);
    printf("2 + 3 = %d\n", res);

    return 0;
}