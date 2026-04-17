#include <stdlib.h>
#include <stdio.h>

void f(char *arr, int size) {
    printf("\n\n");
    for (int i = 0; i < size; i++) {
        printf("%c ", *arr);
        arr++;
    }
}

int main(void) {
    char arr[3][10] = {"Erant", "Roi", "capitan"};
    
    char *p = &arr[0][0];
    
    size_t size = sizeof(arr) / sizeof(arr[0][0]);
    for (int i = 0; i < size; i++) {
        printf("%c ", *p);
        p++;
    }
    
    void (*p_)(char *, int);
    p_ = f;
    p_(&arr[0][0], size);
    
    return 0;
}