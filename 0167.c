#include <stdio.h>

void fun(int *x, int *y) {
    *x += *y;
}

int fun2(int x, int y) {
    return x + y;
}

int main(void) {
    // вариант 1
    int a = 5, b = 3;
    fun(&a, &b);
    printf("%d\n", a);
    
    for (int i = 0; i < 20; i++)
        printf("—");
    
    // вариант 2
    a = 4, b = 9;
    int res = fun2(a, b);
    printf("\n%d", res);
    
    return 0;
}