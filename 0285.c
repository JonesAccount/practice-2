#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    for (;;) printf("heh");
    
    return 0;
}