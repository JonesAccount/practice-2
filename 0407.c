#include <stdio.h>

void foo(char *arr) {
    static int index = 0;
    static char *names[10];
    names[index] = *arr;
    for (int i = 0; i < 10; i++) {
        printf("%s\n", *(arr + i));
    }
}

int main(void) {
    char arr[50];
    printf("Имя: ");
    scanf(" %[^\n]", arr);
    
    void (*p)(char*);
    p = foo;
    
    
    return 0;
}