#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int n = 10;
    n >>= 1; // 00101
    n <<= 1; // 00010
    printf("%d", n);
    
    return 0;
}