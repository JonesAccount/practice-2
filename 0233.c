#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define SIZE 26

int main(void) {
    char text[] = {"Dynamic memory allocation allows a programmer to allocate, resize, and free memory at runtime. Key advantages include."};
    
    while (1) {
        int *_ = (int *)calloc(SIZE, sizeof(int));
        if (NULL == _) { return 1; }
        
        int code = 0;
        for (int i = 0; i < SIZE; i++) {
            _[i] = 97 + code; code++;
        }
        
        int counter = 0;
        for (int i = 0; i < strlen(text); i++) {
            for (int j = 0; j < SIZE; j++) {
                if (tolower(text[i]) == _[j]) { counter++; }
            }
            printf("%c: %d\n", tolower(text[i]), counter);
            counter = 0;
        }
        
        
        getchar(); system("clear"); free(_);
    }
    
    return 0;
}