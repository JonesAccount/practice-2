#include <stdlib.h>
#include <stdio.h>

int main() {
    int a = 8;
    int *p = &a;
    *p++;
    printf("%d", p);
    
}