#include <string.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    char *str = {"Windows"};
    
    for (int i = 0; i < strlen(str); i++) {
        printf("%c - %p\n", *(str + i), (void *)(str + i));
    }
    
    return 0;
}