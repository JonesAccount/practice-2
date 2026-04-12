#include <stdio.h>

#define LINE printf("\n-------------------------\n");

int main(void) {
    printf("\033[?25l");
    
    int q = 45057;
    int *pQ = &q;
    printf("Тип: int\nЗначение: %d\nАдрес: %p", *pQ, (void *)pQ);
    
    LINE
    
    short w = 1005;
    short *pW = &w;
    printf("Тип: short\nЗначение: %hd\nАдрес: %p", *pW, (void *)pW);
    
    LINE
    
    char e = 'E';
    char *pE = &e;
    printf("Тип: char\nЗначение: %c\nАдрес: %p", *pE, (void *)pE);
    
    LINE
    
    float r = 100.5f;
    float *pR = &r;
    printf("Тип: float\nЗначение: %.2f\nАдрес: %p", *pR, (void *)pR);
    
    LINE
    
    double t = 377632.8656;
    double *pT = &t;
    printf("Тип: double\nЗначение: %.3f\nАдрес: %p", *pT, (void *)pT);
    
    LINE
    
    size_t y = 888;
    size_t *pY = &y;
    printf("Тип: size_t\nЗначение: %zu\nАдрес: %p", *pY, (void *)pY);
    
    return 0;
}