#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **args) {
        printf("\033[?25l");
        
        int a;
        a = 5; //0101
        a <<= 1;
        int *p;
        p = &a;
        *p += 1; //1010
        
        printf("%d", *p);
        
        return 0;
}