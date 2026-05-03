#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
  
    int rows = 0;
    int column = 0;
    
    printf("[R] ");
    scanf("%d", &rows);
    printf("[C] ");
    scanf("%d", &column);
    
    int **arr = (int *)malloc(rows * sizeof(int *));
    if (NULL == arr) { return 1; }
    
    for (int i = 0; i < rows; i++) {
        arr[i] = calloc(column, sizeof(int));
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            arr[i][j] = j + 1;
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    free(arr);
    
    return 0;
}