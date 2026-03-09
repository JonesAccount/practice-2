#include <stdio.h>

unsigned short int counter = 1, counter_space = 4;

void kernel(void) {
    for (short int i = 0; i < 8; i++) {
        for (short int j = 0; j < counter_space; j++)
            printf(" ");
        for (short int k = 0; k < counter; k++)
            printf("*");
        counter++; counter_space--;
        printf("\n");
    }
}