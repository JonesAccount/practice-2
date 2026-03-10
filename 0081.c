#include <stdio.h>

int main() {
    short x = 4;
    short * pX = &x;
    
    printf("Адрес через амперсанд: %p\n", &x);
    
    printf("Адрес через указатель: %p\n", pX);
    
    printf("Значение: %hd", *pX);
}