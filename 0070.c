#include <stdio.h>

int f(int num);

int main(void) {
    printf(">>> ");
    int number;
    scanf("%i", &number);
    int res = f(number);
    printf("%i", res);
    return 0;
}

int f(int num) {
    int res = num * 2;
    return res;
}