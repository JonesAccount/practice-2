#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 55, b = 55;
    
    int c = a & b;
    int d = a == b;
    
    printf("%d %d", c, d);
    
    return 0;
}