#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    fflush(stdout);
    
    while (1) {
        int counter = 15;
        for (int i = 0; i < 16; i++) {
            unsigned short n = 1;
        
            int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        
            arr[counter] = 1;
            counter--;
            for (int j = 0; j < 16; j++) {
                printf("%d ", arr[j]);
            }
        
            n <<= i;
            printf("\n\n%d\n", n);
        
            usleep(100000);
            system("clear");
        }
    }
    
    return 0;
}