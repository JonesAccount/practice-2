#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int arr[10] = {0};
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    
    int *p = arr;
    
    p[5] = 0;
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", p[i]);
    }
    
    return 0;
}