#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 0, b = 0, c = 0;
    int min = 0, ave = 0, max = 0;
    int nod = 0;
    
    while (1) {
        printf("Число a: "); scanf("%d", &a);
        printf("Число b: "); scanf("%d", &b);
        printf("Число c: "); scanf("%d", &c);
        
        min = (a < b) ? a : b;
        max = (b > a) ? b : a;
        
        
        if (a < b) {
            if (a < c) {
                min = a;
            } else {
                min = c;
            }
        } else {
            if (b < c) {
                min = b;
            } else {
                min = c;
            }
        }
        
        if (a > b) {
            if (a > c) {
                max = a;
            } else {
                max = c;
            }
        } else {
            if (b > c) {
                max = b;
            } else {
                min = c;
            }
        }
        
        if (min != c && max != c) { ave = c; }
        if (min != c && max != c) { ave = c; }
        
        
        printf("%d %d %d", min, ave, max);
        getchar(); getchar();
        
        
        printf("\nНОД: ");
        for (int i = 1; i <= min; i++) {
            if ((min % i) == 0) {
                if ((max % i) == 0) { nod = i; }}
        }
        printf("%d", nod);
        getchar(); getchar(); system("clear");
    }
    
    return 0;
}