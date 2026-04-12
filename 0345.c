#include <stdio.h>

int main(void) {
    int arr[] = {5, 8, 2, 9, 2, 7, 9, 0};
    
    int *p = arr + 5;
    
    // цель: получить число 5
    printf("%d", (*(p - 1) + *(arr + 1)) / *(p - (*(arr + 1) - *arr)));
    
    return 0;
}