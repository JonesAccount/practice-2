#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    // массив в куче
    int *ptr = (int *)malloc(5 * sizeof(int));
    if (NULL == ptr) { return 1; }
    
    ptr[0] = 1;
    ptr[3] = 4;
    ptr[4] = 5;
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    
    int *tmp = realloc(ptr, 7 * sizeof(int));
    if (!tmp) {
        free(ptr); return 1;
    }
    
    ptr = tmp;
    
    printf("\n\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", ptr[i]);
    }
    
    return 0;
}