#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

#define LINE "---------------------------"
#define N "\n"

typedef struct {
    int y;
    int x;
} PointSnake;

void print_snake(PointSnake *positions, size_t size) {
    printf("\t^\n");
    for (int i = 0; i < size; i++) {
        printf("\to %d|%d\n", positions[i].y, positions[i].x);
    }
    printf("\t@" N);
}

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

int main(void) {
    printf("\033[?25l");
    size_t size = 0;
    
    PointSnake *positions = (PointSnake *)malloc(1 * sizeof(PointSnake));
    if (NULL == positions) { printf("error"); return 1; }
    
    positions[0].y = 1;
    positions[0].x = 1;
    
    while (1) {
        size++;
        print_snake(positions, size);
        
        PointSnake *tmp = realloc(positions, size);
        if (NULL == tmp) { printf("error"); free(positions); return 1; }
        
        positions = tmp;
        
        printf(N LINE N);
        
        for(int i = 0;;i++) {
            
            if (i != 0) {
                print_snake(positions, size);
                printf(N LINE N);
            }
            
            int temp_num = 0;
            printf("Position Y: ");
            
            if (scanf("%d", &temp_num) == 1) {
                if (temp_num > 0 && temp_num < 10) {
                    positions[size].y = temp_num;
                    break;
                }
            }
            
            clear_screen();
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
        }
        
        clear_screen();
        print_snake(positions, size);
        printf(N LINE N);
        
        for(int i = 0;;i++) {
            
            if (i != 0) {
                print_snake(positions, size);
                printf(N LINE N);
            }
            
            int temp_num = 0;
            printf("Position X: ");
            
            if (scanf("%d", &temp_num) == 1) {
                if (temp_num > 0 && temp_num < 10) {
                    positions[size].x = temp_num;
                    break;
                }
            }
            
            clear_screen();
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
        }
        
        clear_screen();
    }
    
    return 0;
}