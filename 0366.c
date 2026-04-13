#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    char st1[] = {"Hello"};
    char st2[] = {"GoodBye!"};
    
    void *p = st1;
    printf("%s\n", *((char *)p));
    
    return 0;
}