#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int check_size(int *arr) {
    int size = 0;
    
    while (*arr >= 0 && *arr <= 9) {
        size++; arr++;
    }
    
    return size;
}

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    int arr[7] = {4, 7, 3, 2, 9, 5, 0};
    
    int size_real = sizeof(arr) / sizeof(arr[0]);
    int size_func = check_size(arr);
    
    printf("Размер массива через sizeof: %d\n", size_real);
    printf("Размер массива в функции: %d", size_func);
    
    (void)getchar();
    printf("\033[?25h");
    
    return 0;
}