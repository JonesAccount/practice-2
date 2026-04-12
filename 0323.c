#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 5;
    char b = 'j';
    
    void *p = &a;
    void *p1 = &b;
    
    printf("%d", *((int *)p));
    
    printf("%c", *((char *)p1));
    return 0;
    
}