#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {
    char arr[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    memset(arr, 0, sizeof(arr));
    
    printf("\n\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}