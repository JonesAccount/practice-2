#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    const int ROWS = 3;
    const int COLS = 3;
    
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n\n");
    
    int *p = &matrix[0][0];
    for (size_t i = 0; i < 9; i++) {
        printf("%d ", *(p + i));
    }
    
    return 0;
}