#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int counter = 4;
    
    int *arr = (int *)calloc(counter, sizeof(int));
    if (NULL == arr) { return 1; }
    
    int *arr_ = (int *)malloc(sizeof(int) * counter);
    if (NULL == arr_) { return 1; }
    
    for (int i = 0; i < counter; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < counter; i++) {
        printf("%d ", arr_[i]);
    }
    
    return 0;
}