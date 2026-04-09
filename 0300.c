#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 5; // 00101
    int b = 2; // 00010
    int c = a ^ b; // 00111
    printf("%d", c);
    
    return 0;
}