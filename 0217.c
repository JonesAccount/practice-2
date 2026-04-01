#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void sort(int *arr) {
    bool separator = true;
    int num = 0;
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
    
    printf("\n\nРезультат: ");
    for (int i = 0; i < 5; i++) { printf("%d ", arr[i]); }
}

int main(void) {
    printf("\033[?25l");
    
    int arr[5] = {0};
    
    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("%d# число: ", i + 1);
            if (scanf("%d", &arr[i]) == 1) { break;
            } else { while (getchar() != '\n'); }
        }
    }
        
    sort(arr);
    
    return 0;
}