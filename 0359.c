#include <stdio.h>

int main(void) {
    int arr[] = {7, 4, 8};
    
    printf("%d | %p\n", *arr, (void *)arr);
    printf("%d | %p\n", *(arr + 1), (void *)arr + 1);
    printf("%d | %p\n", *(arr + 2), (void *)arr + 2);
    
    return 0;
}