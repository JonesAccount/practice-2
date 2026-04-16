#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void into_minus(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) > 0) {
            arr[i] = *(arr + i) - (*(arr + i) * 2);
        }
    }
}

void into_plus(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int number = 0, temp = 0;
        if (*(arr + i) < 0) {
            temp = *(arr + i);
            while (temp != 0) { temp++; number++; }
            *(arr + i) = number;
        }
    }
}

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    printf("%p\n", (void *)into_minus);
    printf("%p\n", (void *)into_minus + 1);
    printf("%p\n", (void *)into_minus + 2);
    printf("%p\n", (void *)printf);
    printf("%p\n", (void *)main);
    printf("%p\n", (void *)srand);
    printf("%p\n", (void *)getchar);
    
    printf("\033[?25h");
    
    return 0;
}