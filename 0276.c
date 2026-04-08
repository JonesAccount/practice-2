#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    
    static int flag = 0;
    if (!flag) {
        srand(time(NULL));
        flag = 1;
    }
    
    int arr[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    while (1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                arr[i][j] = rand() % 2;
            }   
        }
        
        for (int i = 0; i < 4; i++) {
           for (int j = 0; j < 4; j++) {
               
               printf("%d ", arr[i][j]);
               
               if (((j + 1) % 4) == 0) {
                   printf("\n");
               }
               
           }
        }
        
        printf("\n\n");
        
        int counter = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("Лампа №%d: %s\n", counter, (arr[i][j] == 1) ? "\033[33mвключена\033[0m" : "\033[31mвыключена\033[0m");
                counter++;
            }   
        }
        
        usleep(100000);
        system("clear");
    }
    
    return 0;
}