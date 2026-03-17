#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 

int main(void) {
    fflush(stdout);
    short number, step = 10;
    short *pN = &number;
    short start = *pN;
    printf("[?] ");
    scanf("%hd", pN);
    do {
        for (int i = 0; i < 3; i++)
            printf("\n");
        for (int i = 0; i < 5; i++) {
            *pN *= 2;
            for (int j = 0; j < step; j++)
                printf(" ");
            printf("%hd\n", *pN);
            step++;
            usleep(100000);
        }
        *pN = start;
        step = 10;
        system("clear");
    } while (1);
    
}