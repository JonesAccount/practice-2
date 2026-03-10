#include <stdio.h>

int func(short *x);

int main() {
    short num = 0;
    short * pNum = &num;
    short res = func(pNum);
    printf("%hi", res);
    return 0;
}

int func(short *x) {
    (*x)++;
    return *x;
}