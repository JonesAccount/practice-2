#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 0, b = 0, min = 0, max = 0, nod = 0;
    
    while (1) {
        printf("Число a: "); scanf("%d", &a);
        printf("Число b: "); scanf("%d", &b);
        
        min = (a < b) ? a : b;
        max = (b > a) ? b : a;
        
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