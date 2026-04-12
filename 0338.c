#include <stdio.h>

int main(void) {
    int a = 5;
    int *p = &a;
    
    --(*p);
    int b = ++(*p);
    printf("%d", b++);
    
    return 0;
}