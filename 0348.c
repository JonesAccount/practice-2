#include <stdlib.h>
#include <stdio.h>

int main(void) {
    
    int *p = (int *)malloc(sizeof(int) * 100);
    if (NULL == p) { return 1; }
    
    for (int i = 0; i < 100; i++) {
        *(p + i) = i + 1;
    }
    
    while (1) {
        
    }
    
    return 0;
}