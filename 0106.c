#include <stdio.h>

int main(void) {
    short num = 5;
    printf("%13hd\n", num);
    printf("%9hd", num);
    printf("%8hd\n", num);
    printf("%13hd", num);
}