#include <stdio.h>

int main(void) {
    int n = 'A';
    n = n - n + 1;
    printf("%d", n);
    
    return 0;
}