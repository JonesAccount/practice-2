#include <stdio.h>

int main(void) {
    int a = !1;
    printf("%d\n", a);
    
    int b = !0;
    printf("%d\n", b);
    
    int c = !5;
    printf("%d\n", c);
    
    int d = 5 && 3;
    printf("%d\n", d);
    
    int e = 2 && 0;
    printf("%d\n", e);
    
    int f = -5 || 8;
    printf("%d\n", f);
    
    int g = 0 || 0;
    printf("%d\n", g);
    
    int h = - 9 && 0 || 5;
    printf("\n%d\n", h);
    
    return 0;
}