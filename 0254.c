#include <stdio.h>

int main(void) {
    int a = 5, b = 3;
    int c = 7, d = 8;
    
    printf("%f", (float)a / b);
    
    c = c+++d;
    printf("\n%d", c);
    int z = c+++d++;
    printf("\n%d", z);
    int o = c++*c++*c--*c++/50-c--;
    printf("\n%d", o);
    
    int p = 8;
    int q = 7;
    int v = p---q;
    printf("\n\np = %d \n", p);
    printf("q = %d \n", q); 
    printf("v = %d \n", v); 
    
    
    return 0;
}