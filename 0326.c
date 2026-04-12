#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 7;
    printf("%d | %d\n", a, '&');
    
    char b = '&';
    
    int *p = &a;
    char *pb = &b;
    
    *p = *p + *pb;
    
    printf("%d | %d\n", a, '&');
    printf("%d", *p);
    
    return 0;
}