#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define YELLOW "\033[33m"
#define RESET "\033[0m"

void fill_cash(int *);
void show_cash(int *);
float accountant(int count, ...);
void clear_screen(void);

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    while (1) {
        int cash[10] = {0};
        fill_cash(cash);
        
        printf("\033[1mГОРБАТИМ НА ЛЕНИНСКОМ ЗАВОДЕ!!!\nТРУДЯГИ!!!\033[0m\n\nПолучаем баксы, делим на человек\n");
        show_cash(cash);
        
        // 1
        printf("\n\nДень 1: ");
        printf(YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ ", cash[3], cash[8], cash[5]);
        printf("\nВсем достанется по %.1f баксов.", accountant(3, cash[3], cash[8], cash[5]));
        
        // 2
        printf("\n\nДень 2: ");
        printf(YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ ", cash[3], cash[8], cash[5], cash[1], cash[9], cash[2]);
        printf("\nВсем достанется по %.1f баксов.", accountant(6, cash[3], cash[8], cash[5], cash[1], cash[9], cash[2]));
        
        // 3
        printf("\n\nДень 3: ");
        printf(YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " YELLOW "%d" RESET "$ " RESET, cash[3], cash[8], cash[5], cash[1], cash[9], cash[2], cash[7], cash[6], cash[4]);
        printf("\nВсем достанется по %.1f баксов.", accountant(8, cash[3], cash[8], cash[5], cash[1], cash[9], cash[2], cash[7], cash[6], cash[4]));
        
        (void)getchar();
        clear_screen();
    }
    
    return 0;
}

void fill_cash(int *cash) {
    int *p = cash;
    
    for (int i = 0; i < 10; i++) {
        *(p + i) = rand() % (9 - 1 + 1) + 1;
    }
}

void show_cash(int *cash) {
    for (int i = 0; i < 10; i++) {
        printf("\033[33m%d\033[0m$ ", cash[i]);
    }
}

float accountant(int count, ...) {
    va_list ap;
    va_start(ap, count);
    
    int total = 0;
    
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, int);
    }
    
    va_end(ap);
    return (float)total / 5;
}

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}