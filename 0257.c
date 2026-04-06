#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort(int *arr) {
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    printf("\033[?25l");
    
    int arr[10];
    for (int i = 0; i < 10; i++) {
        while (1) {
            int n = rand() % 10;
            int flag = 0;
            
            for (int j = 0; j < i; j++) {
                if (arr[j] == n) {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0) {
                arr[i] = n;
                break;
            }
        }
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    sort(arr);
    
    printf("\n\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}