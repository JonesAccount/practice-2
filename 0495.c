#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {
    char arr[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        memset(arr, i, sizeof(arr));
    }
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}