#include <stdarg.h>
#include <stdio.h>

short max(int count, ...) {
    va_list ap;
    va_start(ap, count);
    
    auto int total = va_arg(ap, int);
    auto int tmp = 0;
    for (size_t i = 0; i < count - 1; i++) {
        tmp = va_arg(ap, int);
        if (tmp > total) { total = tmp; }
    }
    
    va_end(ap);
    return (short)total;
}

short min(int count, ...) {
    va_list ap;
    va_start(ap, count);
    
    auto int total = va_arg(ap, int);
    auto int tmp = 0;
    for (size_t i = 0; i < count - 1; i++) {
        tmp = va_arg(ap, int);
        if (tmp < total) { total = tmp; }
    }
    
    va_end(ap);
    return (short)total;
}

short average(int count, ...) {
    va_list ap;
    va_start(ap, count);
    
    auto int total = 0;
    for (size_t i = 0; i < count; i++) {
        total += va_arg(ap, int);
    }
    
    va_end(ap);
    return (short)(total / count);
}

int max_or_min(int flag, int count, ...) {
    va_list ap;
    va_start(ap, count);
    
    auto int total = va_arg(ap, int);
    auto int tmp = 0;
    
    for (size_t i = 0; i < count - 1; i++) {
        
        if (flag) {
            tmp = va_arg(ap, int);
            if (tmp > total) { total = tmp; }
        } else {
            tmp = va_arg(ap, int);
            if (tmp < total) { total = tmp; }
        }
        
    }
    
    va_end(ap);
    return total;
}

int main(int argc, char *argv[]) {
    printf("%hd ", max(5, 5, 2, 8, 9, 1));    // ожидаем 9
    printf("%hd ", max(4, 100, 3, 77, 42));   // ожидаем 100
    printf("%hd ", max(3, -5, -1, -9));       // ожидаем -1
    printf("%hd ", max(6, 3, 3, 3, 3, 3, 9)); // ожидаем 9
    
    printf("\n\n");
    
    printf("%hd ", min(5, 5, 2, 8, 9, 1));    // ожидаем 9
    printf("%hd ", min(4, 100, 3, 77, 42));   // ожидаем 100
    printf("%hd ", min(3, -5, -1, -9));       // ожидаем -1
    printf("%hd ", min(6, 3, 3, 3, 3, 3, 9)); // ожидаем 9
    
    printf("\n\n");
    
    printf("%hd ", average(5, 5, 2, 8, 9, 1));    // ожидаем 9
    printf("%hd ", average(4, 100, 3, 77, 42));   // ожидаем 100
    printf("%hd ", average(3, -5, -1, -9));       // ожидаем -1
    printf("%hd ", average(6, 3, 3, 3, 3, 3, 9)); // ожидаем 9
    
    printf("\n\n");
    
    printf("%hd ", max_or_min(1, 5, 5, 2, 8, 9, 1));    // ожидаем 9
    printf("%hd ", max_or_min(0, 4, 100, 3, 77, 42));   // ожидаем 100
    printf("%hd ", max_or_min(1, 3, -5, -1, -9));       // ожидаем -1
    printf("%hd ", max_or_min(0, 6, 3, 3, 3, 3, 3, 9)); // ожидаем 9
    
    return 0;
}