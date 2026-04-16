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
    
    while (1) {
        const size_t SIZE = rand() % (10 - 5 + 1) + 5;
        int arr[SIZE];
        
        for (int i = 0; i < SIZE; i++) {
            *(arr + i) = rand() % (10 - (-10) + 1) + (-10);
        }
            
        printf("Исходник:\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", *(arr + i));
        }
    
        into_minus(arr, SIZE);
    
        printf("\n\nОбработка (-):\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", *(arr + i));
        }
    
        into_plus(arr, SIZE);
    
        printf("\n\nОбработка (+):\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", *(arr + i));
        }
        
        (void)getchar();
        clear_screen();
    }
    
    printf("\033[?25h");
    
    return 0;
}