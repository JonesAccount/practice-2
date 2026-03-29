#include <stdio.h>

int main(void) {
    int n = 5; // 00000101
    printf("%d", n);
    
    n <<= 2; // 00010100
    printf("\n%d", n);
    
    n >>= 2; // 00000101
    printf("\n%d", n);
    
    n >>= 2; // 00000001
    printf("\n%d", n);
    
    n >>= 1; // 00000000
    printf("\n%d", n);
    
    n <<= 5; // 00000000
    printf("\n%d", n);
    
    return 0;
}