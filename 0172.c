#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
    fflush(stdout);
    unsigned short nums[500] = {0};
    unsigned short *pN = nums;
    while (1) {
        pN = nums;
        for (int i = 0; i < 500; i++) {
            *pN = rand() % 2;
            pN++;
        }
    
        for (int i = 0; i < 500; i++) {
            if ((i % 25) == 0) printf("\n");
            printf("%d", nums[i]);
        }
        usleep(100000);
        system("clear");
    }
        
}