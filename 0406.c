#include <stdio.h>

void foo() {
    static int n = 0;
    n++;
    printf("%d ", n);
}

int main(void) {
    void(*p)();
    p = foo;
    p();
    p();
    p();
    p();
    
    return 0;
}