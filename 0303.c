#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PIXELS 1100

void clear_screen(void) {
    printf("\033[2J");  
    printf("\033[H");   
    fflush(stdout);     
}

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    fflush(stdout);
    
    char arr[PIXELS];
    for (int i = 0; i < PIXELS; i++) {
        arr[i] = ' ';
    }
    
    printf("\n\n\t  ");
    for (int i = 0; i < PIXELS; i++) {
        printf("\033[47m%c\033[0m", arr[i]);
        if (((i + 1) % 50) == 0) { printf("\n\t  "); }
    }
    
    clear_screen();
    while (1) {
        printf("\n\n\t  ");
        for (int i = 0; i < PIXELS; i++) {
            int index = rand() % PIXELS;
            printf("\033[41m%c\033[0m", arr[index]);
            if (((i + 1) % 50) == 0) { printf("\n\t  "); }
            usleep(1000000);
        }
        
        clear_screen();
    }
    
    return 0;
}