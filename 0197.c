#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WAIT getchar();
#define CLEAR system("clear");
#define RANDOM rand() % 101;

typedef unsigned short int usint;

usint res = 0, win = 0, lose = 0;
usint x, y, input;
bool res_counter = false;

usint *i = &input;

void interface(void);


int main(void) {
    srand(time(NULL));
    printf("\033[?25l");
    
    do {
        x = RANDOM
        y = RANDOM
        res = x + y;
        
        interface();
        scanf("%hd", i);
        
        res_counter = true;
        CLEAR
        
        if (*i == res) {
            win++;
            interface();
            printf("\033[32mверно\033[0m");
        } else {
            lose++;
            interface();
            printf("\033[31mневерно\033[0m");
        }
        
        WAIT WAIT CLEAR
        res_counter = false;
        
    } while (true);
    
    return 0;
}


void interface(void) {
    printf("Найти значение выражения\n");
    printf("\nПобеда: \033[32m%hd\033[0m\nПоражение: \033[31m%hd\033[0m\n\n", win, lose);
    printf("Задача: %hd + %hd = %s", x, y, (res_counter) ? "" : "?");
    if (res_counter) { printf("%hd", res); }
    printf("\n\n[?] ");
}