#include <stdio.h>

#define ROWS 10
#define COLS 10

char map[ROWS * COLS];

void fill_board(char *map) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0  j == 0  i == ROWS || j == COLS - 1) {
                map[i * j] = '#';
            }
        }
    }
}

void print_board(char *map) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i* j]);
        }
        printf("\n");
    }
}

int main(void) {
    
    fill_board(map);
    print_board(map);
    
    return 0;
}