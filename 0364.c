#include <stdio.h>

int main(void) {
    int arr[3][4];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = j;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = j + 1;
        }
    }
    
    for (int (*ptr)[4] = arr; ptr <= &arr[3]; ptr++) {
        for (int *temp = &arr[0]; temp <= &arr[0][3]; temp++) {
            printf("%d ", arr[ptr][temp]);
        }
        printf("\n");
    }
    
    
    return 0;
}