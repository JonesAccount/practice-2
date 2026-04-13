#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    int *p = NULL;
    
    int x = 10;
    p = &x;
    printf("%d\n", *p);
    
    int y = 20;
    p = &y;
    printf("%d\n", *p);
    
    const int z = 30;
    p = &z;
    printf("%d", *p);
    
    return 0;
}