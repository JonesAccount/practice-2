#include <stdio.h>

#define printf(x) printf("%d\n", x * 2)

int main(void) {
    //printf("\033[?25l");
    
    printf(2);
    int y = 5;
    printf(y);
    
    return 0;
}