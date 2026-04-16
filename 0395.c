#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int tolow(char *arr, const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = tolower(*(arr + i));
    }
    
    return 0;
}

int main(void) {
    printf("\033[?25l");
    
    char arr[] = {'S', 'x', 'O', 'p'};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    int (*ft)(char*, const int);
    ft = tolow;
    ft(arr, size);
    
    for (int i = 0; i < size; i++) {
        printf("%c ", *(arr + i));
    }
    
    return 0;
}