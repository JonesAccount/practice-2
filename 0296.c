#include <stdio.h>

int main(void) {
    int a = 4; // 0100
    int b = 3; // 0011
    
    int c = a ^ b; // 0111
    
    printf("%d", c);
}