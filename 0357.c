#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 20;
    const int c = 30;
    //c = 40;
    // через переменную нельзя
    
    int *pc = &c;
    *pc = 40;
    // можно менять значение
    
    const int *pa = &a;
    int *const pb = &b;
    
    a++;
    --b;
    
    printf("%d\n", *pa);
    (*pb)++;
    
    printf("%d %d\n", *pa, *pb);
    printf("%d", *pc);
    
    
    return 0;
}