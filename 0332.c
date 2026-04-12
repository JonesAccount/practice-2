#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("\033[?25l");
    
    int a = 1;
    int *p = &a;
    
    *p = *p + 1;
    *p += 1;
    *p *= 3;
    *p /= 3;
    *p -= 2;
    
    printf("%d\n", (*p + 1) * 3);
    
    (*p)++;
    printf("%d", *p);
    
    return 0;
}