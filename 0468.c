#include <stdio.h>

typedef struct {
    int a;
    int b;
} Point;

Point square(Point st) {
    return (Point){st.a * st.a, st.b * st.b};
}

int main(void) {
    Point st = {4, 5};
    Point sq = square(st);
    
    printf("%d\n", sq.a);
    printf("%d\n", sq.b);
    
    return 0;
}