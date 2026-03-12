#include <stdio.h>

int main(void) {
    int arr[2][3] = {
        {6, 8, 2},
        {0, 1, 5}
    };
    
    for (short i = 0; i < 2; i++) {
        for (short j = 0; j < 3; j++) {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
    
}