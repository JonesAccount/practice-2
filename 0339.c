#include <stdio.h>

int main(void) {
    int a = 5;
    int *p = &a;
    
    --*p;
    (*p)++;
    (*p)--;
    printf("%d", ++*p);
    
    return 0;
}