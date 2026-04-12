#include <stdio.h>

int func() {
    return 0;
}

int main(void) {
    printf("\033[?25l");
    
    int *a, *b, *c;
    
    int *d = NULL;
    int *e = NULL;
    
    int (*fptr)() = func;
    
    printf("%d", *a);
    
   // int *b = nullptr;
    
    int w = 6, m = 9, o;
    
    int *pW = &w;
    int *pM = &m;
    
    o = *pW;
    *pW = *pM;
    *pM = o;
    
    
    printf("\n\n%d %d", *pW, *pM);
    
    
    return 0;
}