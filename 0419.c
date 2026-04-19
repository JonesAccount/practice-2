#include <stdio.h>

#define ROWS 20
#define COLS 21

char playground[ROWS * COLS];

void fill_playground(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0  j == 0 i == (ROWS - 1) || j == (COLS - 1)) {
                playground[i * COLS + j] = '#';
            } else {
                playground[i * COLS + j] = ' ';
            }
        }
    }
}

void print_playground(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            putchar(playground[i * COLS + j]);
        }
        putchar('\n');
    }
}

int main(void) {
    fill_playground();
    print_playground();
    return 0;
}