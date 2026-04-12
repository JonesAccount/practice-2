#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 5, b = 3;
    int *p = &a;
    void *p_ = &b;
    
    printf("%d\n", *p < *((int *)p_));
    int z = 10;
    *p = 10; int *p__ = &z;
    printf("%d\n", *p == *p__);
    
    printf("%p | %p\n%p", (void *)p, (void *)p + 1, (void *)p__);
    printf("\n%d", p >= p__);
    
    return 0;
}