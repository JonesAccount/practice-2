#include <stdio.h>

int main(void) {
    int a = 5;
    int b = 9;
    
    void *p = &a;
    printf("%d", *(((int *)p) - 1));
    
    return 0;
}