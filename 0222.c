#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef unsigned short int usint;

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    usint size = 0;
    
    while (1) {
        size = rand() % 100 + 1;
        
        int *arr = (int*)malloc(sizeof(int) * size);
        
        if (NULL == arr) {
            printf("Ошибка при выделении памяти в куче");
            return 1;
        }
        
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100 + 1;
        }
        
        unsigned int bytes = size * 4;
        unsigned int bits = bytes * 8;
        float kb = (float)bytes / 1024;
        float mb = kb / 1024;
        
        printf("Массив создан в куче\n");
        printf("\nТип данных: int\nБайт: %d\nБит: %d\nКилобайт: %f\nМегабайты: %f", bytes, bits, kb, mb);
        
        getchar(); system("clear");
        
        free(arr);
    }
    
    return 0;
}