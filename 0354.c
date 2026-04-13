#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    const int x = 10;
    const int *const p = &x;
    
    //x = 20;
    //*p = 20;
    //int y = 20; p = &y;
    
    printf("%d\n", *p);
    
    return 0;
}