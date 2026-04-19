#include <stdio.h>

int main(void) {
    const register int n = 1844674407370955161;
    //const register int *p = &n;
    //printf("%d\n", n);
    
    int res = 0;
    for (register int i = 1; i <= 1000000000; i++) {
        res++;
    }
    
    printf("%d", res);
    
    return 0;
}