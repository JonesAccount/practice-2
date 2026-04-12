#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int x = 9; int *pX = &x;
    int y = 3; int *pY = &y;
    
    printf("Адрес х: %p", (void *)pX);
    printf("\nЗначение x: %d", *pX);
    
    printf("\n\nАдрес y: %p", (void *)pY);
    printf("\nЗначение y: %d", *pY);
    
    *pY = *pX;
    
    printf("\nЗначение y: %d", *pY);
    
    char a = 'A';
    char *pA = &a;
    
    printf("\n\n%c | %p", *pA + 1, (void *)pA);
    
    return 0;
}