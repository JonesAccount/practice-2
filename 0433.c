#include <stdio.h>
 
int left_shift(int n) {
    return n << 1;
}

int rigth_shift(int n) {
    return n >> 1;
}

int main(void) {
    const int NUM = 5;
    auto int tmp = 0;
    
    int (*p[2])(int) = {left_shift, rigth_shift};
    
    tmp = p[0](NUM);
    printf("%d\n", tmp);
    
    tmp = p[1](NUM);
    printf("%d\n", tmp);
    
    return 0;
}