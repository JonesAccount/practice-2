#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    const int a = 6;
    const int *p = &a;
    
    int b = 8;
    void *pb = &b;
    (*(int *)pb)++;
    
    printf("%d, %d", a, *(int *)pb);
    
    return 0;
}