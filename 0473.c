#include <stdlib.h>
#include <stdio.h>

int foo(void) {
    static int *p;
    if (NULL == p) { p = (int *)malloc(sizeof(int)); }
    (*p)++;
    return *p;
}

int main(void) {

    for (int i = 0; i < 5; i++) {
        printf("%d\n", foo());
    }

    return 0;
}
