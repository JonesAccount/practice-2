#include <stdio.h>

int *foo() {
    int x = 42;
    return &x;
}

int main() {
    int *p = foo();
    printf("%d\n", *p);
    
    (*p)++;
    printf("%d\n", *p);
    
}