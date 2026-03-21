#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iso646.h>

int main(void) {
    fflush(stdout);
    printf("\033[?25l");
    short s = 0, d = 0, e = 0;
    
    while (s != 1) {
        printf("%hd | %hd | %hd\n", s, d, e);
        
        e++;
        
        if (e == 9 and d == 9) {
            s++;
            e = 0;
            d = 0;
        } else if (e == 9) {
            d++;
            e = 0;
        }
        
        usleep(100000);
        system("clear");
    }
    
    printf("%hd | %hd | %hd\n", s, d, e);
    
    return 0;
}