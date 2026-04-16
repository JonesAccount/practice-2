#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    {
        int z = 8;
        printf("%d", z);
    }
    
    printf("%d", z);
    
    return 0;
}