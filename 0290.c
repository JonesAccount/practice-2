#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    int arr[rand() % (100 - 1 + 1) + 1];
    
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
        printf("%d ", arr[i]);
    }
    
    printf("\n\nРазмер: %d", size);
    
    return 0;
}