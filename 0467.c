#include <stdio.h>

typedef struct {
    int a;
    int b;
    int c;
} Point;

Point create(int x, int y ) {
    return (Point){x, y, x + y};
}

int main(void) {
    Point st = create(4, 5);
    
    printf("%d\n", st.a);
    printf("%d\n", st.b);
    printf("%d\n", st.c);
    
    return 0;
}