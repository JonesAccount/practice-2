#include <stdio.h>

int main(void) {
    short i = 5;
    --i;
    i--;
    ++i;
    printf("%hd", i);
}