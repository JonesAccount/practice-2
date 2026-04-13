#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    char *str1, *str2;
    char *str1[] = "word";
    char *str2[] = "word";
    
    printf("%p\n", str1);
    printf("%p\n", str2);
    
    return 0;
}