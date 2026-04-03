#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int *num = (unsigned int *)malloc(sizeof(unsigned int) * 1);
    
    int n = 4294967295;
    *num = n;
    
    printf("%d", *num);
    
    
    return 0;
}