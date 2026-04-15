#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define R255 rand() % (255 - 0 + 1) + 1;
#define cout printf
#define BOLD "\033[1m"

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    char *str = "Hello, world!";
    
    int R, G, B;
    R = R255;
    G = R255;
    B = R255;
    
    for (;;) {
        printf("\033[38;2;200;50;0m%s\033[0m\n", str);
        getchar();
    }
    
    return 0;
}