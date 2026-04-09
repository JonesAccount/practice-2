#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define _1_20 rand() % (15 - 1 + 1) + 1;

void print_binary(unsigned short n);
void clear_screen(void);

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    while (1) {
        short x = 0, y = 0;
        x = _1_20; y = _1_20;
        
        printf("Побитовое ИЛИ (|)\n");
        
        printf("\nЧисло х: %d ( ", x);
        print_binary(x);
        
        printf("Число y: %d ( ", y);
        print_binary(y);
        
        int z = x | y;
        printf("\nРезультат: %d ( ", z);
        print_binary(z);
        
        (void)getchar();
        clear_screen();
    }
    
}

void print_binary(unsigned short n) {
    for (short i = sizeof(n) * 2 - 1; i >= 0; i--) {
        printf("%d ", (n >> i) & 1);
    }
    printf(")\n");
}

void clear_screen(void) {
    printf("\033[2J");  
    printf("\033[H");   
    fflush(stdout);     
}