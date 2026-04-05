#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    printf("\033[?25l");
    
    while (1) {
        size_t arrBytes = 0;
        size_t sizeArr = (rand() % (20 - 10 + 1) + 10);
        char *arr = (char *)malloc(sizeof(char) * sizeArr);
        
        if (NULL == arr) {
            printf("error");
            return 1;
        }
        
        for (size_t i = 0; i < sizeArr; i++) {
            arr[i] = rand() % (126 - 32 + 1) + 32;
            arrBytes += sizeof(char);
        }
        
        for (size_t i = 0; i < sizeArr; i++) {
            printf("%d. %c\n", i + 1, arr[i]);
        }
        
        printf("\nКоличество элементов: %zu", sizeArr);
        printf("\nМассив занимает: %zu байтов", arrBytes);
        
        getchar();
        system("clear");
        free(arr);
        
    }
    
    return 0;
}