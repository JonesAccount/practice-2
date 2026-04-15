#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    char *str = {"Windows"};
    printf("%c%c%c\n", *(str + 3), *(str + 1), *(str + 2));
    
    str[3] = 'b';
    
    printf("%c\n", *str);
    
    return 0;
}