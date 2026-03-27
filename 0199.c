#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    int x, y, z, res;
    
    while (1) {
        
        while (x < 10 && x > 100) {
            x = rand() % 10000;
        }
        
        y = rand() % 100000000;
        z = 0;
        
        printf("1: %d\n2: %d", x, y);
        
        getchar();
        
        res = x + y;
        printf("\nОтвет: %d", res);
        
        getchar(); system("clear");
    }
    return 0;
}
