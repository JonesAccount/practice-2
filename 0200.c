#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef unsigned short int usi;

int main(void) {
    srand(time(NULL));
    printf("\033[?25l");
    
    usi one1, one2;
    usi two1, two2, two3;
    usi three1, three2, three3;
    
    while (1) { 
        for (int i = 0; i < 2; i++) {
            one1 = rand() % 10;
            one2 = rand() % 10;
    
            two1 = rand() % 10;
            two2 = rand() % 10;
            two3 = rand() % 10;
    
            three1 = rand() % 10;
            three2 = rand() % 10;
            three3 = rand() % 10;
    
            printf("Число %d: %hd%hd.%hd%hd%hd.%hd%hd%hd\n", i + 1, one1, one2, two1, two2, two3, three1, three2, three3);
        }
        
        getchar();
        system("clear");
    }
    
    return 0;
}