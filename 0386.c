#include <stdlib.h>
#include <stdio.h>

int main(void) {
    
    short arr[] = {3, 7, 1, 9, 2};
    
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    // первое задание
    for (short *ptr = arr; ptr <= &arr[size - 1]; ptr++) {
        printf("%hd ", *ptr);
    }
    
    // второе задание
    short max = *arr;
    for (short *ptr = arr + 1; ptr <= &arr[size - 1]; ptr++) {
        if (*ptr > max) { max = *ptr; }
    }
    
    printf("\n\n%hd\n\n", max);
    
    // третье задание
    for (short *ptr = &arr[size - 1]; ptr >= arr; ptr--) {
        printf("%hd ", *ptr);
    }
    
    return 0;
}