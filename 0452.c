#include <stdio.h>

void main(void) {
    #define A
    #ifndef A
        printf("No");
    #endif 
    
    #ifdef A
        printf("Yes");
    #endif
}