#include <stdlib.h>
#include <stdio.h>

int main(void) {
    long int arr[5] = {5, 8, 3, 9, 2};
    
    long int *ptr = arr;
    ptr[1] = 4;
    *(ptr + 3) = 1;
    *(ptr) = 10;
    
    for (int i = 0; i < 5; i++) {
        printf("%ld ", ptr[i]);
    }
    
    printf("\n\n");
    
    for (long int *ptr = arr; ptr <= &arr[4]; ptr++) {
        printf("%ld ", *ptr);
    }
    
    
    return 0;
}