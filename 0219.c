#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int N = 0;
    printf("Куча: ");
    scanf("%d", &N);
    
    int *A = (int *)malloc(N);
    
    for (int i = 0; i < N; i++) {
        A[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    
    return 0;
}