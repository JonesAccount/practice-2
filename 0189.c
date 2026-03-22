#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int D;

typedef struct {
    D index1;
    D index2;
    D index3;
} ST;

ST s[10];

int indexmax;

int main(void) {
    srand(time(NULL));
    printf("\033[?25l");
    while (1) {
        
        for (D i = 0; i < 10; i++) {
            s[i].index1 = rand() % 10;
            s[i].index2 = rand() % 10;
            s[i].index3 = rand() % 10;
        }
        
        D max = 0; D nums[10];
        
        for (D i = 0; i < 10; i++)
            nums[i] = s[i].index1 + s[i].index2 + s[i].index1;
        
        for (D i = 0; i < 10; i++) 
            if (s[i].index1 + s[i].index2 + s[i].index1 > max) {
                max = s[i].index1 + s[i].index2 + s[i].index1;
                indexmax = i;
            }
        
        printf("Структура #%d\n", indexmax + 1);
        printf("1|Член — %d\n", s[indexmax].index1);
        printf("2|Член — %d\n", s[indexmax].index2);
        printf("3|Член — %d\n", s[indexmax].index3);
        printf("Сумма: %d", max);
        
        getchar(); system("clear");
    }
    
    return 0;
}