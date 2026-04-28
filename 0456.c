#include <stdio.h>

int main(void) {
    #ifdef clang
        puts("clang compiler\n");
    #elif GNUC
        puts("gcc compiler");
    #else
        puts("not a fined");
    #endif
    
    #ifdef x86_64
        puts("64 bit");
    #elif i386
        puts("32 bit");
    #else
        puts("bit not exist");
    #endif
    
    return 0;
}