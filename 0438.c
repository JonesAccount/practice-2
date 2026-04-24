#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...) {
    va_list ap;
    va_start(ap, count);
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, int);
    
    }
    
    va_end(ap);
    
    return total;
}

int main(int argc, char *argv[]) {
    printf("%d\n", sum(3, 5, 3, 1));
    printf("%d\n", sum(6, 5, 3, 1, 1, 5));
    printf("%d\n", sum(9, 5, 3, 1, 1, 2, 9, 4, 7, 2));
    
    return 0;
}