#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int oper(int (*p)(int, int), int a, int b) {
    return p(a, b);
}

int main(int argc, char *argv[]) {
    int arr[] = {5, 5};
    int *p = arr;
    int c = oper(sum, *p, *(p + 1));
    printf("%d\n", c);
    
    return 0;
}