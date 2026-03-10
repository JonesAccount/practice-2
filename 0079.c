#include <stdio.h>

int main() {
    short x = 4;
    float y = 5.9;
    printf("%p\n", &x);
    printf("%p\n", &x);
    printf("%p", &y);
}