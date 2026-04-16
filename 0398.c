#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

void foo(void) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        if (i == 5) { break; }
    }
    
    return;
}

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    void (*p)(void);
    p = foo;
    p();
    
    return 0;
}