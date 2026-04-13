#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    int x = 10, y = 60;
    int *const p = &x;
    *p = 20;
    
    p = &y;
    
    printf("%d\n", *p);
    
    return 0;
}