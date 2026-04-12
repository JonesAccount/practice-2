#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define BOLD "\033[1m"
#define RED "\033[31m"

typedef unsigned int Uint4;

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
}

int main() {
    printf("\033[?25l");
    srand(time(NULL));
    fflush(stdout);
    
    while (1) {
        Uint4 *arr = (Uint4 *)calloc(0, sizeof(Uint4));
        
        if (NULL == arr) { return 1; }
        
        for (size_t i = 0;; i++) {
            Uint4 *tmp = realloc(arr, (i + 1) + sizeof(Uint4));
            
            if (NULL == tmp) { return 1; }
            
            arr = tmp;
            
            arr[i] = rand() % (4294967295 - 0 + 1) + 1;
            char *p = (char *)&arr[i];
        
            printf(BOLD "Value: = \033[34m%d\033[0m", arr[i]);
            printf(BOLD "\nSize: \033[31m%zu bytes\033[0m | \033[33m%d bits\033[0m", sizeof(arr[i]), sizeof(arr[i]) * 8);
            
            printf(BOLD "\n\nMemory address:\n");
            printf( BOLD "Byte №1: \033[31m%p\033[0m\n", p);
            for (int j = 0; j < 8; j++) {
                printf(BOLD "\t\tBit №%d: \033[33m0x%zu\033[0m\n", j + 1, p + 1 + (j + 1));
            }
            printf(BOLD "Byte №2: \033[31m%p\033[0m\n", p + 1);
            for (int j = 0; j < 8; j++) {
                printf(BOLD "\t\tBit №%d: \033[33m0x%zu\033[0m\n", j + 1, p + 2 + (j + 1));
            }
            printf(BOLD "Byte №3: \033[31m%p\033[0m\n", p + 2);
            for (int j = 0; j < 8; j++) {
                printf(BOLD "\t\tBit №%d: \033[33m0x%zu\033[0m\n", j + 1, p + 3 + (j + 1));
            }
            printf(BOLD "Byte №4: \033[31m%p\033[0m\n", p + 3);
            for (int j = 0; j < 8; j++) {
                printf(BOLD "\t\tBit №%d: \033[33m0x%zu\033[0m\n", j + 1, p + 4 + (j + 1));
            }
            
            
            usleep(100000);
            clear_screen();
        }
    }
    
    return 0;
}