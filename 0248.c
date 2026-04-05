#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    fflush(stdout);
    printf("\033[?25l");
    unsigned short n = 0;
    
    while (1) {
        
        if (n > 65000 || n < 300) {
            n++;
        } else {
            n += 100;
        }
        
        printf("%hu\n", n);
        usleep(1);
        system("clear");
    }
    
    return 0;
}