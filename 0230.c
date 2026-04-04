#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define INTEGER sizeof(int)

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    while (1) {
        int index = 0, check = 0, num = 0;
        int counter = rand() % 9 + 1;
        
        int *arr = (int *)malloc(INTEGER * 1);
        if (NULL == arr) { printf("error"); return 1; }
        
        while (index < counter) {
            
            int *tmp = realloc(arr, (index + 1) * INTEGER);
            if (NULL == tmp) { free(arr); printf("error"); return 1; }
            arr = tmp;
            
            num = rand() % 10; check = 0;
            
            for (int i = 0; i < index + 1; i++) {
                if (arr[i] == num) { check = 1; } 
            }
            
            if (!check) { arr[index] = num; index++; }
            
        }
        
        for (int i = 0; i < counter; i++) {
            printf("\033[1m%d\033[0m ", arr[i]);
        }
        
        
        getchar(); system("clear"); free(arr);
    }
    
    return 0;
}