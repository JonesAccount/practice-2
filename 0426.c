#include <stdio.h>

int foo(void) {
    return 5 + 4;
}

int main(void) {
    printf("%d\n", foo());
    int a = foo();
    printf("%d\n", a);
    int b = a;
    return 0;
}