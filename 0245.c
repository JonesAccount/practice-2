#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t size;
    char text[] = {"Circle"};
    size = strlen(text);
    printf("%zu", size);
    return 0;
}