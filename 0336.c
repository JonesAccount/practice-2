#include <stddef.h>
#include <stdio.h>

int main() {
    printf("\033[?25l");
    
    int arr[100] = {0};
    for(int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }
    
    int *ps = &arr[0];
    int *pe = &arr[99];
    ptrdiff_t r = pe - ps;
    
    
    printf("%td", r);
    
    return 0;
}