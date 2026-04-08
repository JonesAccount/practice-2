#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int c, n;
    c = n = 0;
    
    for (int i = 0; i <= 9; i++) {
        if ((i % 2) != 0) { continue; }
        c += i;
    }
    
    for (int i = 0; i <= 9; i++) {
        if ((i % 2) == 0) { continue; }
        n += i;
    }
    
    for (int i = 0; i <= 9; i++) {
        printf("%d ", i);
    }
    
    printf("\nЧетные: %d", c);
    printf("\nНечетные: %d", n);
    
    return 0;
}