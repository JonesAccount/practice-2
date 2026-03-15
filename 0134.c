#include <stdlib.h>
#include <stdio.h>

int main() {
    int a = 500;
    int *p = &a;
    int **b = &p;
    
    printf("%d", b);
    
}