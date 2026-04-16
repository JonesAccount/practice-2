#include <stdlib.h>
#include <stdio.h>

void foo(void) {
    printf("foo! | ");
}

int sum(int a, int b) {
    return a + b;
}

void char_coperatiom_septions(char a, int b) {
    printf("\n\n%c", a + b);
}

int main(void) {
    printf("\033[?25l");
    
    void (*f)(void);
    f = foo;
    f();
    printf("%p\n", foo);
    
    int (*psum)(int, int);
    psum = sum;
    short res = (short)psum(3, 5);
    printf("%hd", res);
    
    
    void (*smp)(char, int);
    smp = char_coperatiom_septions;
    smp(35, 30);
    
    return 0;
}