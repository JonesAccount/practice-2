#include <stdio.h>

#define W 6

void main(void) {
    while (1) {
        #if W == 6
            printf("exist\n");
        #else
            printf("not exist\n");
        #endif
        
        (void)getchar();
        system("clear");
    }
}