#include <stdlib.h>
#include <stdio.h>

#define SIZE 26

int main(void) {
    printf("\033[?25l");
    
    char *l = (char *)malloc(sizeof(char) * SIZE);
    
    short start = 65;
    for (int i = 0; i < SIZE; i++) {
        l[i] = start; start++;
    }
    
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", l[i]);
    }
    
    free(l);
    
    return 0;
}