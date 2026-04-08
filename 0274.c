#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *ASKII;
    
    ASKII = (int *)calloc(1, sizeof(int));
    
    if (NULL == ASKII) {
        return 1;
    }
    
    ASKII[0] = 32;
    
    int size = 126 - 31;
    for (int i = 0; i < size; i++) {
        int *tmp = realloc(ASKII, (i + 1) * sizeof(int));
        
        if (NULL == tmp) {
            free(ASKII);
            return 1;
        }
        
        ASKII = tmp;
    }
    
    
    
    for (int i = 1, j = 33; j <= 126; i++, j++) {
        ASKII[i] = j;
    }
    
    for (int i = 0, j = 32; i < size; i++, j++) {
        printf("Номер: \033[32m%d\033[0m | Символ: \033[33m%c\033[0m\n", j, ASKII[i]);
    }
    
    return 0;
}