#include <stdio.h>

int main(void) {
    struct Student {
        int age;
        char name[10];
    };
    
    struct Student *st1;
    
    st1 -> age = 18;
    strcpy(st1 -> name, "James");
    
    printf("%d | %s\n", (*st1).age, st1 -> name);
    
    return 0;
}