#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void reset(int *p);
void reset_arr(int *arr);

int main(void) {
    srand(time(NULL));
    int x = 5;
    int *p = &x;
    
    int *arr = (int *)malloc(5 * sizeof(int));
    
    for (int i = 0; i < 5; i++) {
        *arr = rand() % (100 - 1 + 1) + 1;
        arr++;
    }
    
    printf("%d\n", x);
    reset(p);
    printf("%d\n", x);
    
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr++);
    }
    
    return 0;
}

void reset(int *p) {
    *p = 0;
}

void reset_arr(int *arr) {
    for (int i = 0; i < 5; i++) {
        *arr = 0;
        arr++;
    }
}