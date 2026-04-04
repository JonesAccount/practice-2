#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    while (1) {
        int arr[8];
        
        for (int i = 7; i >= 0; i--) {
            arr[i] = rand() % 2;
        }
        
        for (int i = 0; i < 8; i++) {
            printf("%d ", arr[i]);
        }
        
        int counter = 1, result = 0;
        for (int i = 7; i >= 0; i--) {
            if (arr[i] == 1) {
                result += counter;
            }
            counter *= 2;
        }
    
        printf("\n\nРезультат: %d", result);
        
        getchar();
        system("clear");
    }
    
    return 0;
}