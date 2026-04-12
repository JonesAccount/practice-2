#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 5;
    
    int *p1 = &a;
    void *p2 = &a;
    
    printf("%p\n", (void *)p1);
    printf("%p\n", p2);
    
    return 0;
}