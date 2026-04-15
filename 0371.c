#include <stdio.h>

int main(void) {
    printf("\033[?25l");

    int arr[3] = {1, 2, 3};
    int *p;
    p = &arr;
    printf("%p | %d\n", (void *)p, *(int *)(p));
    printf("%p | %d\n", (void *)(p + 1), *(int *)(p + 1));
    printf("%p | %d\n", (void *)(p + 2), *(int *)(p + 2));

    return 0;
}
