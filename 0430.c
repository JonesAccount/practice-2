#include <stdio.h>

void foo(int arr[static 4]) {
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(arr + i));
    }
    
    int *const p = &arr[4];
    printf("%d", *p);
}

int main(void) {
    int arr[] = {5, 4, 2, 7, 2, 9, 1};
    foo(arr);
    
    return 0;
}