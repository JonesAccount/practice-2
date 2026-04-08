#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define STRONG "\033[1m"
#define RESET "\033[0m"

void printf_memory(int bits[4][4], int value);
void clear_screen(void);

int main(void) {
    printf("\033[?25l");
    
    static int flag = 0;
    if (!flag) {
        srand(time(NULL));
        flag = 1;
    }
    
    int bits[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    while (1) {
        
        int bit_index = 15, value = 0;
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                bits[i][j] = rand() % 2;
                value += bits[i][j] * (1 << bit_index);
                bit_index--;
            }   
        }
        
        printf_memory(bits, value);
        
        int counter = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf(STRONG "bit №%s%d: ", (counter <= 9) ? "0" : "", counter);
                printf(STRONG "%s", (bits[i][j] == 1) ? "\033[32mHI \033[0m" : "\033[31mLO \033[0m");
                
                if (((j + 1) % 4) == 0) { printf("\n"); }
                
                counter++;
                
            }   
        }
        
        usleep(99000);
        clear_screen();
    }
    
    return 0;
}

void printf_memory(int bits[4][4], int value) {
    printf(STRONG "\t\t    MEMORY\n");
    printf(STRONG "      ———————————————————————————————————\n      | ");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf(STRONG "%d ", bits[i][j]);
        }
    }
    printf(STRONG "|\n      ———————————————————————————————————");
        
    printf("\n\n");
    printf(STRONG "\t\t value: %d", value);
    printf("\n\n");
}

void clear_screen(void) {
    printf("\033[2J");  
    printf("\033[H");   
    fflush(stdout);
}