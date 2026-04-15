#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    const int ROWS = 4;
    const int COLS = 4;
    const int SIZE = ROWS * COLS;
    
    int arr[ROWS][COLS] = {0};
    
    int *p = &arr[0][0];
    
    for (int i = 0; i < SIZE; i++) {
        *p = rand() % (10 - (-10) + 1) + (-10);
        p++;
    }
    
    p -= SIZE;
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        int n = *(p + i);
        sum += n;
        if (n < 0) { printf("%d ", n); }
        if ((i + 1) % COLS == 0) { printf("\n"); }
    }
    
    printf("\n\nСумма всех элементов: %d", sum);
    
    (void)getchar();
    printf("\033[?25h");
    
    return 0;
}