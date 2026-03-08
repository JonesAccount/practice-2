#include <stdio.h>

int main(void) {
    
    short int i = 1;
    
    while (i < 6) {
        printf("%hd\n", i);
        i++;
    }
    
    return 0;
}