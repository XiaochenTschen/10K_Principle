#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main() {
    char s_arr[20];
    strcpy(s_arr, "test.h");

    printf("size of s_arr: %ld\n", sizeof(s_arr));          // 20
    printf("size of s_arr string: %ld\n", strlen(s_arr));   // 6
    printf("s_arr content: %s\n", s_arr);                   // test.h

    memset(s_arr, ' ', 20);
    strncpy(s_arr, "test.h", strlen("test.h"));

    printf("size of s_arr: %ld\n", sizeof(s_arr));          // 20      
    printf("size of s_arr string: %ld\n", strlen(s_arr));   // 22 
    printf("s_arr content: %s\n", s_arr);                   // test.h + backspace + simbol             

    return 0;
}