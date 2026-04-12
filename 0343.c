#include <stdio.h>

int main(void) {
    int arr[] = {5, 8, 2, 9, 2, 9, 0};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < size; i++) {
        printf("%d\n", *(arr + i));
    }
    
    int nums[size];
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        nums[j] = arr[i];
    }
    
    printf("\n");
    
    for (int i = 0; i < size; i++) {
        printf("%d\n", *(nums + i));
    }
    
    return 0;
}