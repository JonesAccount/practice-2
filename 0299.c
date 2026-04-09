#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int n = 5;
    
    unsigned int a = ~n;
    printf("%u", a);
    
    a = ~a;
    printf("\n%u", a);
    
    return 0;
}