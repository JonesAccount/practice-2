#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    typedef struct {
        char name[50];
        float version;
    } Program;
    
    Program *pr[5];
    
    for (int i = 0; i < 5; i++) {
        pr[i] = malloc(sizeof(Program));
    }
    
    strcpy(pr[0] -> name, "Tetris");
    strcpy(pr[1] -> name, "Calculator");
    strcpy(pr[2] -> name, "Map");
    
    pr[0] -> version = 4.5f;
    pr[1] -> version = 2.1f;
    pr[2] -> version = 7.9f;
    
    for (int i = 0; i < (sizeof(pr) / sizeof(pr[0])) - 2; i++) {
        printf("%-8s\t", pr[i] -> name);
        printf("v.%.1f\n", pr[i] -> version);
    }
    
    return 0;
}