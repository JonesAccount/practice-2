#include <stdio.h>

void fun(int *x, int *y) {
    *x += *y;
}

int main(void) {
    int a = 5, b = 3;
    fun(&a, &b);
    printf("%d", a);
    return 0;
}