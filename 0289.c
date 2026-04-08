#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    printf("Вариант 1: ");
    int arr1[5] = {0};
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    
    printf("\n\n");
    
    int arr2[5] = {};
    printf("Вариант 2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    
    printf("\n\n");
    
    int arr3[5];
    printf("Вариант 3: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr3[i]);
    }
    
    printf("\n\n");
    
    int arr4[5];
    printf("Вариант 4: ");
    for (int i = 0; i < 5; i++) {
        arr4[i] = 0;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr4[i]);
    }
    
    
    return 0;
}