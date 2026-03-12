#include <stdio.h>

int main(void) {
    int arr[3][4] = {
        {6, 8, 46, 0},
        {0, 100, 5, 6},
        {68, 433, 99, 3}
    };
    
    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}