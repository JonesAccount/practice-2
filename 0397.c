#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

int foo(void) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        if (i == 5) { return 0; }
    }
}

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    int (*p)(void);
    p = foo;
    p();
    
    return 0;
}