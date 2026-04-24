#include <stdio.h>

int n = 0;

void temperX(void) {
    n = 10;
}

void temperY(void) {
    n = -10;
}

int main(void) {
    void (*p)(void);
    
    printf("%d\n", n);
    
    p = temperX;
    p();
    printf("%d\n", n);
    
    p = temperY;
    p();
    printf("%d\n", n);
    
    return 0;
}