#include <stdio.h>

void foo(void) {
    int x;
    int flag = 1;
    if (flag) {
        x = 5;
        flag = 0;
    }
    
    printf("%d\n", x);
    
}

int main(void) {
    
    foo();
    foo();
    
    return 0;
}