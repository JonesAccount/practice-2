#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    int arr[5] = {0};
    int num = 0;
    bool separator = true;
    
    for (int i = 0; i < 5; i++) {
        arr[i] = rand() % 10;
    }
    
    printf("Исходник: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    while (separator) {
        for (int i = 0; i < 5; i++) {
            if (i != 4) {
                if (arr[i + 1] < arr[i]) {
                    num = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = num; num = 0;
                    separator = true;
                } else {
                    separator = false;
                }
            }
        }
    }
        
    
    printf("\n\nОтсортированный: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}