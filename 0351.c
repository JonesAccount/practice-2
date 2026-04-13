#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    int x = 10;
    const int *p = &x;
    *p = 20;
    
    printf("%d", x);
    
    return 0;
}