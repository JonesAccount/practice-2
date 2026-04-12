#include <stdio.h>

int main(void) {
    int a = 5;
    int *p1;
    int *p2 = &a;
    
    p1 = &a;
    p2 -= 8;
    
    ptrdiff_t result = p1 - p2;
    
    printf("%td", result * sizeof(int));
    
    return 0;
}