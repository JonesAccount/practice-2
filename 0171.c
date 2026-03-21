#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int x[] = {5, 8, 7, 8};
    printf("%d\n", x[2]);
    printf("%d", *(x+2));
    return 0;
}