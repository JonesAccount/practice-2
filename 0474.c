#include <stdlib.h>
#include <stdio.h>

typedef struct {
	unsigned int x:2;
} St;

int foo(void) {
    static St *p;
    if (NULL == p) { p = (St *)malloc(sizeof(St)); }
    p -> x++;
    return (*p).x;
}

int main(void) {

    for (int i = 0; i < 10; i++) {
        printf("%d\n", foo());
    }

    return 0;
}
