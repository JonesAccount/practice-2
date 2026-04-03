#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int *num = (int *)malloc(sizeof(int) * 1);
    
    *num = 99;
    
    printf("%d", *num);
    
    
    return 0;
}