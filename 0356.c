#include <stdio.h>

int main(void) {
    const float pi = 3.14f;
    const float *p = &pi;
    
    printf("Число пи: %.2f", *p);
    
    return 0;
}