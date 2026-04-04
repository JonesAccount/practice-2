#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RAND rand() % 9 + 1;
#define RESET "\033[0m"
#define FATTY "\033[1m"

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    while (1) {
        int *arr = (int *)malloc(sizeof(int) * 1);
        if (NULL == arr) { printf("error"); return 1; }
        arr[0] = RAND
        
        int counter = RAND
        for (int i = 0; i < counter; i++) {
            int *tmp = realloc(arr, (i + 1) * sizeof(int));
            if (NULL == tmp) { free(arr); printf("error"); return 1; }
            arr = tmp; arr[i + 1] = RAND
        }
        
        printf(FATTY "Исходный массив в куче:\n" RESET);
        for (int i = 0; i < counter; i++) {
            printf("\033[34m%d\033[0m ", arr[i]);
        }
        
        int delValue = RAND
        printf(FATTY "\n\nЗначение для удаления:\n" RESET);
        printf("\033[31m%d\033[0m", delValue);
        
        int sizeForNewArr = 0;
        for (int i = 0; i < counter; i++) {
            if (arr[i] != delValue) { sizeForNewArr++; }
        }
        
        int *newArr = (int *)malloc(sizeof(int) * sizeForNewArr);
        int index = 0;
        for (int i = 0; i < counter; i++) {
            int *newTmp = realloc(newArr, (i + 1) * sizeof(int));
            if (NULL == newTmp) { free(newArr); printf("error"); return 1; }
            newArr = newTmp;
            
            if (arr[i] != delValue) { newArr[index++] = arr[i]; }
            
        }
        
        arr = newArr;
        
        printf(FATTY "\n\nИзмененный массив в куче:\n" RESET);
        for (int i = 0; i < sizeForNewArr; i++) {
            printf("\033[34m%d\033[0m ", arr[i]);
        }
        
        getchar(); system("clear");
        free(arr);
    }
    
    return 0;
}