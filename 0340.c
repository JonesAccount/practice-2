#include <stdio.h>

int main(void) {
    int a = 5;
    
    void *p = &a;
    printf("%d\n", ++*(int *)p);
    
    printf("%d\n", *(int *)p);
    
    printf("%d\n", (--(*(int *)p)) - 1);
    
    printf("%d\n", *(int *)(p + 9));
    
    
    return 0;
}