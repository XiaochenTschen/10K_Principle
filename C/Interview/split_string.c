#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b? a : b;
}

int maxScore(char* s) {
    size_t len = strlen(s);
    int score_left = 0, score_right = 0;
    for(int i = 0; i < len; ++i) {
        if(s[i] == '1') ++score_right;
    }
    if(s[0] == '0')
        score_left = 1;
    else
        --score_right;

    int max_score = score_left + score_right;
    for(int i = 1; i < len-1; ++i) {
        if(s[i] == '0') {
            ++score_left;
        }
        else {
            --score_right;
        }
        max_score = max(max_score, score_left + score_right);
    }
    return max_score;
}

int main(void) {
    char s[] = "00111";

    int res = maxScore(s);

    return 0;
}