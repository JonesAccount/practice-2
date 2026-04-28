#include <stdio.h>

int main(void) {
    #ifdef clang
        puts("clang compiler\n");
    #elif GNUC
        puts("gcc compiler");
    #else
        puts("not a fined");
    #endif
    
    return 0;
}