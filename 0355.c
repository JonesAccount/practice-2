#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    const int x = 10, y = 44;
    int *const p = &x;
    
    *p = 20;
    //p = &y;
    
    printf("%d\n", *p);
    
    const int *px = &x;
    //*px = 30;
    px = &y;
    printf("%d\n", *px);
    
    const int c = 66;
    const int *const pc = &c;
    printf("%d\n", *pc);
    
    return 0;
}