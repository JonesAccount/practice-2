#include <stdio.h>

int main(void) {
    char st[] = {"Hello"};
    char *p = st;
    
    for (int i = 0; i < 6; i++) {
        if (i < 5) {
            printf("%c  | ", *(st + i));
        } else {
            printf("\\0 | ");
        }
        
        printf("%p\n", &st[i]);
    }
    
    return 0;
}