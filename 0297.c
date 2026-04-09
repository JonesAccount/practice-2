#include <stdio.h>

int main(void) {
    int a = 2; // 0010
    int b = 4; // 0100
    
    int c = a | b; // 0110
    
    printf("%d", c);
}