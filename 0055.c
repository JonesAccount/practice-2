#include <stdio.h>

int main(void) {
    
    char name[50];
    printf("Ваше имя: ");
    scanf("%49s", &name);
    
    for (short int i = 1; i < 6; i++) {
        printf("%i. %s\n", i, name);
    }
    
    return 0;
}