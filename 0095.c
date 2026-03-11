#include <stdio.h>

int main(void) {
    short a, b, max, min;
    printf("Первое число: ");
    short * pA = &a; scanf("%hd", pA);
    printf("Второе число: ");
    short * pB = &b; scanf("%hd", pB);
    
    max = (a > b) ? a : b;
    min = (a < b) ? a : b;
    
    printf("\n%hd больше чем %hd", max, min);
}