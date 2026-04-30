#include <stdio.h>

typedef struct {
    int var;
} struct_one;

typedef struct {
    int a;
    int b;
    struct_one c;
} struct_two;

int main(void) {
    struct_two st = {1, 2, .c.var = 3};
    
    printf("%d\n", st.a);
    printf("%d\n", st.b);
    printf("%d\n", st.c.var);
    
    return 0;
}