#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int a;
    int b;
} St;

void print_st(St st) {
    printf("%d %d\n", st.a, st.b);
}

void modify_point(St *st) {
    (*st).a++;
    st -> b++;
}

St modify(St st) {
    St temp = st;
    temp.a++;
    temp.b++;
    return temp;
}

St modify_lite(St st) {
    st.a++;
    st.b++;
    return st;
}

int main(void) {
    printf("\033[?25l");
    
    St st = {5, 3};
    print_st(st);
    
    modify_point(&st);
    print_st(st);
    
    st = modify(st);
    print_st(st);
    
    st = modify_lite(st);
    print_st(st);
    
    return 0;
}