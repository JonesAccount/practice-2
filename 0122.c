#include <stdio.h>

int main(void) {
    short a, b;
    printf(">>> ");
    scanf("%hd%hi", &a, &b);
    printf("%hd", a + b);
    
    return 0;
}