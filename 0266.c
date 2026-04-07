#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int n = 2; // 0010
    printf("%d\n", n);
    
    n <<= 1; // 0100
    printf("%d\n", n);
    
    n <<= 1; // 1000
    printf("%d\n", n);
    
    n >>= 2; // 0010
    printf("%d\n", n);
    
    n >>= 2; // 0000
    printf("%d\n", n);
    
    n <<= 4; // 0000
    printf("%d\n", n);
    
    
    return 0;
}