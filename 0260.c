#include <stdio.h>

int counter(void) {
    static int n = 0;
    return ++n;
}

int main(void) {
    
    printf("%d\n", counter());
    printf("%d\n", counter());
    printf("%d\n", counter());
    printf("%d\n", counter());
    
    for (int i = 0; i < 5; i++)
        printf("%d\n", counter());
    
    return 0;
}