#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf(">>> ");
    char i = getchar(); getchar();
    printf("Символ: ");
    putchar(i);
    printf("\nКод: %d", i);
}