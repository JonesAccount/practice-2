#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    const int ROWS = 4;
    const int COLS = 4;
    const int SIZE = ROWS * COLS;
    
    int *arr = (int *)calloc(sizeof(int), ROWS);
    if (NULL == arr) { printf("error"); return 1; }
    
    int *p = arr;
    
    for (int *ptr = p; ptr <= &p[ROWS - 1]; ptr++) {
        *ptr = *(int *)malloc(COLS * sizeof(int));
    }
    
    for (int i = 0; i < SIZE; i++) {
            *p = rand() % (10 - -10 + 1) + 1;
            p++;
    }
    
    p -= SIZE;
    for (int i = 0; i < SIZE; i++) {
            printf("%s%d ", (*p < 10) ? "0" : "", *p);
            if ((i + 1) % COLS == 0) { printf("\n"); }
            p++;
    }
    
    (void)getchar();
    printf("\033[?25h");
    
    return 0;
}