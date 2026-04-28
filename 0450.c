#include <stdio.h>
#include <ctype.h>

#define VAR(x) printf(#x " = %d\n", x)
#define VAR2(x) printf(#x " = %d\n", x * x)
#define STRING(var) printf(#var " = %c\n", toupper(var))

int main(void) {
    printf("\033[?25l");
    
    int num = 5; VAR(num);
    int square = 2; VAR2(square);
    char l = 'a'; STRING(l);
    
    return 0;
}