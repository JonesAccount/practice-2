#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    
    int *p = (int *)malloc(sizeof(int) * 100);
    if (NULL == p) { return 1; }
    
    for (int i = 0; i < 100; i++) {
        *(p + i) = i + 1;
    }
    
    ptrdiff_t z = &p[9] - &p[3];
    
    printf("%td", z);
    
    return 0;
}