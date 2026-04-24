#include <stdio.h>

#define N 1

int main(void) {
    printf("%d\n", N);
    #undef N
    #define N 2
    printf("%d\n", N);
    #undef N
    #define N 3
    printf("%d\n", N);
    
    return 0;
}