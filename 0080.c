#include <stdio.h>

int main() {
    short x = 4;
    short * pX = &x;
    
    printf("%p\n", &x);
    printf("%p", pX);
}