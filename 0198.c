#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    int x, y;
    while (1) {
        x = rand() % 100000000;
        y = rand() % 100000000;
        
        printf("- %d\n- %d", x, y);
        
        getchar(); 
        system("clear");
    }
    return 0;
}