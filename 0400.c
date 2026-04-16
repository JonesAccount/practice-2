#include <stdio.h>

void foo(void) {
    auto const char HI[] = "Hello";
    printf("%s", HI);
}

int main(void) {
    printf("\033[?25l");
    
    void (*p)(void);
    p = foo;
    foo();
    
    return 0;
}