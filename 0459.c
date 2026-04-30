#include <stdio.h>

struct Person {
    int a;
    char b[10];
} tom = {12, "tommy"}, anni = {20, "annie"};

int main(void) {
    
    printf("%d %s\n", tom.a, tom.b);
    printf("%d %s\n", anni.a, anni.b);
    
    return 0;
}