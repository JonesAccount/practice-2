#include <stdio.h>

void foo(int arr[static 4]) {
    for (int i = 0; i < 4; i++) {
        arr[i] = 1;
    }
    
}

int main(void) {
    int arr[] = {5, 4, 2, 7, 2, 9, 6};
    foo(arr);
    
    size_t size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    
    return 0;
}