#include <stddef.h>
#include <stdio.h>

int main() {
    printf("\033[?25l");
    
    int a = 4, b = 7;
    
    int *pa = &a;
    int *pb = &b;
    
    ptrdiff_t c = pa - pb;
    
    printf("a: %p\n", (void *)pa);
    printf("b: %p\n", (void *)pb);
    printf("c: %td", c);
    
    return 0;
}