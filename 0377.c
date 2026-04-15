#include <string.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    char str[] = {"Windows"};
    char *p = str;
    *(str + 3) = 'b';
    *(str) = 'M';
    
    printf("%s", str);
    
    return 0;
}