#include <stdio.h>

int main(void) {
    char st[] = "Hello \0 World!";
    
    printf("%s", st);
}