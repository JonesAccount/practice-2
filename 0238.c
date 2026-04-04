#include <locale.h>
#include <stdio.h>

void main(void) {
    char *locale = setlocale(LC_ALL, "");
    
    unsigned int n = 100U;
    unsigned long long int ln = 555453225762ULL;
    
    printf("%d %llu", n, ln);
    
}