#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RAND rand() % (10 - 1 + 1) + 1;

void clear_screen(void);
int new_elements(int *p, int *pS);

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    while (1) {
        int *arr = (int *)malloc(0);
        int *p = arr;
    
        if (NULL == p) {
            printf("FUCK!");
            return 1;
        }
        
        int size = 0;
        int *pS = &size;
        new_elements(p, pS);
    
        for (int *pI = p, i = 0; pI <= &p[*pS - 1]; pI++, i++) {
            *(p + i) = RAND
        }
    
        for (int *pI = p, i = 0; pI <= &p[*pS - 1]; pI++, i++) {
            printf("%d ", *(p + i));
        }
        
        (void)getchar();
        clear_screen();
    }
    
    return 0;
}

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

int new_elements(int *p, int *pS) {
    *pS = RAND
    for (size_t i = 1; i <= *pS; i++) {
        int *tmp = realloc(p, i * sizeof(int));
        
        if (NULL == tmp) {
            printf("FUCK!");
            free(p);
            return -1;
        }
        
        p = tmp;
        
    }
    
    return 0;
}