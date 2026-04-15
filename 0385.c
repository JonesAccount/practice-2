#include <stdlib.h>
#include <stdio.h>

int main(void) {
    
    int x = 0x41424365;
    char *p = (char*)&x;
    printf("%c %c %c %c\n", p[0], p[1], p[2], p[3]);
    
    return 0;
}