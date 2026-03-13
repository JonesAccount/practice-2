#include <stdio.h>

int main(void) {
    int x = (y = 2) + (z = 2);
    x = (x = 2) * (x = 3);
    x += (x++) + (++x);
    printf("%d", x);
    
    return 0;
}