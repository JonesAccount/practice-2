#include <stdio.h>

void swap_and_divide(int *x, int *y, int *by) {
    int soon = *x;
    *x = *y;
    *y = soon;
    *x /= *by;
    *y /= *by;
}

int main(void) {
    int a, b, c;
    int *pC = &c;
    printf("Первое число | Второе число | Делитель\n[?] ");
    scanf("%d%d%d", &a, &b, pC);
    swap_and_divide(&a, &b, pC);
    
    printf("a: %d\nb: %d", a, b);
    
    return 0;
}