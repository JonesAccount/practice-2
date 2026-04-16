#include <stdlib.h>
#include <stdio.h>

void foo(char *name) {
    static char arr[10][10];
    static int index = 0;
    
    if (index >= 10) {
        printf("Массив заполнен");
        return;
    }
    
    strcpy(arr[index], name);
    
    printf("\n");
    for (int i = 0; i < index + 1; i++) {
        printf("- %s\n", arr[i]);
    }
    printf("\n");
    
    index++;
}

int main(void) {
    static int counter = 1;
    void (*pfoo)(char *);
    pfoo = foo;
    while (1) {
        char buffer[11];
        printf("%d: ", counter);
        scanf("%10s", buffer);
        pfoo(buffer);
        counter++;
    }
    
    return 0;
}