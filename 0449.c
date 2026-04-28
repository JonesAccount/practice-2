#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main(void) {
    printf("\033[?25l");
    
    printf("%d\n", SQUARE(5));
    printf("%d\n", SQUARE(3));
    printf("%d\n", SQUARE(9));
    
    printf("%d\n", SQUARE((2 + 4)));
    printf("%d\n", SQUARE(((1 + 2) * 3)));
    printf("%d\n", SQUARE(8 / 2));
    
    printf("%d\n", SQUARE(2 + 3));
    printf("%d\n", SQUARE(6 - 4));
    
    return 0;
}