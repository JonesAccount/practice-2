#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

int factorial(int);

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    int (*pf)(int);
    pf = factorial;
    printf("%d", pf(5));
    
    return 0;
}

int factorial(int n) {
    if (n == 1) { return 1; }
    return n * factorial(n - 1);
}