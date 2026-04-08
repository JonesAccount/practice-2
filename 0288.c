#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int arr[5] = {10, 20, [4] = 77};
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n\n");
    
    int arr2[5];
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    
    printf("\n\n");
    
    int arr3[5] = {};
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr3[i]);
    }
    
    
    return 0;
}