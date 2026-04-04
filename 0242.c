#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    while (1) {
        int *_2 = (int *)calloc(4, sizeof(int));
        if (NULL == _2) {
            printf("error man");
            return 1;
        }
        
        int number = 1;
        for (int i = 4; i >= 0; i--) {
            printf("Конвертация систем счисления\n\n| ");
            for (int j = 3; j >= 0; j--) {
                printf("%d | ", _2[j]);
            }
            printf("\n\n#%d бит: ", number);
            scanf("%d", &_2[i - 1]);
            number++;
            
            if (i != 0) {
                system("clear");
            }
        }
        
        int counter = 1, result = 0;
        for (int i = 3; i >= 0; i--) {
            if (_2[i] == 1) {
                result += counter;
            }
            counter *= 2;
        }
    
        printf("\nРезультат: %d", result);
        
        getchar();
        getchar();
        system("clear");
        free(_2);
    }
    
    return 0;
}