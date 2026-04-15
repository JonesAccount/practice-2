#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    const int ROWS = 3;
    const int COLS = 3;
    const int SIZE = ROWS * COLS;
    
    int matrix[ROWS][COLS] = {0};
    
    int *p = &matrix[0][0];
    for (int i = 0; i < SIZE; i++) {
        *p = rand() % (9 - 1 + 1) + 1;
        p++;
    }
    
    p -= SIZE;
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i + 1, *(p + i));
    }
    
    printf("\n\n");
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(p + i));
        if ((i + 1) % COLS == 0) { printf("\n"); }
    }
    
    (void)getchar();
    printf("\033[?25h");
    
    return 0;
}