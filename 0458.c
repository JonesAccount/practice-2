#include <stdio.h>

typedef struct {
    int x;
} struct_one;

typedef struct {
    struct_one x;
} struct_two;

typedef struct {
    struct_two x;
} struct_three;

int main(void) {
    struct_three st;
    
    int res = st.x.x.x = 3;
    
    printf("%d\n", res);
    
    return 0;
}