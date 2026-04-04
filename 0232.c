#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 20


int main(void) {
    srand(time(NULL));
    
    while (1) {
        int *arr = (int *)calloc(SIZE, sizeof(int));
        if (NULL == arr) { printf("bitch!"); return 1; }
        
        for (int i = 0; i < SIZE; i++) {
            arr[i] = rand() % 10;
        }
        
        int counter = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (arr[i] == arr[j]) { counter++; }
            }
            printf("Значение/количество: %d | %d\n", arr[i], counter);
            counter = 0;
        }
        
        
        getchar(); system("clear"); free(arr);
    }
    
    return 0;
}