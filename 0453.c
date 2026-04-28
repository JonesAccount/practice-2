#include <stdio.h>

void main(void) {
    printf("\033[?25l");
    while (1) {
        #ifndef X
        printf("not exist");
        #define X
        #endif
        
        #ifdef X
        printf("exist");
        #undef X
        #endif
        
        (void)getchar();
        printf("\033[1;1H\033[2K");
        
    }
}