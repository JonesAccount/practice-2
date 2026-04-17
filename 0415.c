#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char arr[3][10] = {"Erant", "Roi", "capitan"};
    
    char *p = &arr[0][0];
    
    size_t size = sizeof(arr) / sizeof(arr[0][0]);
    for (int i = 0; i < size; i++) {
        printf("%c ", *p);
        p++;
    }
    
    return 0;
}