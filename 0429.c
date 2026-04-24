#include <stdio.h>

void foo(const int *const arr) {
    for (int i = 0; i < 3; i++) {
        printf("%d ", *(arr + i));
    }
}

int main(void) {
    int arr[] = {5, 4, 2};
    foo(arr);
    
    return 0;
}