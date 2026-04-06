#include <stdio.h>

int main(void) {
    int n = 12;
    printf("%d\n", n);
    
    int *p = &n;
    *p = 15;
    printf("%d\n", n);
    
    int **pp = &p;
    **pp = 20;
    printf("%d\n", n);
    
    int ***ppp = &pp;
    ***ppp = 4;
    printf("%d\n", n);
    
    int ****pppp = &ppp;
    ****pppp = 100;
    printf("%d\n", n);
    
    return 0;
}