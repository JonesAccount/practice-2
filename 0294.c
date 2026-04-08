#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int square_matrix(void);
int diagonal_matrix(void);

int main(void) {
    printf("\033[?25l");
    
    square_matrix();
    diagonal_matrix();
    
    return 0;
} 

int square_matrix(void) {
    int arr = (int )calloc(4, sizeof(int*));
    
    if (NULL == arr) {
        return -1;
    }
    
    for (size_t i = 0; i < 4; i++) {
        arr[i] = (int **)malloc(4 * sizeof(int*));
    }
    
    int num = 0;
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            if (num == 9) { num = 0; }
            arr[i][j] = num;
            num++;
        }
    }
    
    printf("Квадратная матрица\n");
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            printf("\033[1m\033[32m%d\033[0m ", arr[i][j]);
        }
        printf("\n");
    }
    
    free(arr);
}

int diagonal_matrix(void) {
    int rows = 5, cols = 5;
    
    int arr = (int )malloc(rows * sizeof(int*));
    
    if (NULL == arr) { return -1; }
    
    for (size_t i = 0; i < rows; i++) {
        arr[i] = (int **)malloc(cols * sizeof(int*));
    }
    
    int num = 1, counter = 1, sep = 5;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (counter == sep) {
                arr[i][j] = num;
                sep--;
                num++;
                counter = 1;
            } else {
                arr[i][j] = 0;
                counter++;
            }
            
        }
    }
    
    printf("\nДиагональная матрица\n");
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("\033[1m\033[32m%d\033[0m ", arr[i][j]);
        }
        printf("\n");
    }
    
     free(arr);
    
}