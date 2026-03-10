#include <stdio.h>

short increment(short *x);

int main(void) {
    short nums[] = {5, 4, 3, 9, 1};
    
    for (short i = 0; i < 5; i++) {
        printf("%hi | %hi\n", i, nums[i]);
    }
    
    printf("\n");
    
    for (short i = 0; i < 5; i++) {
        short * pNum = &nums[i];
        short res = increment(pNum);
        nums[i] = res;
    }
    
    for (short i = 0; i < 5; i++) {
        printf("%hi | %hi\n", i, nums[i]);
    }
}

short increment(short *x) {
    (*x)++;
    return *x;
}