#include <stdio.h>
#include <string.h>

int main(void) {
    char name[10];
    char * pN = &name;
    
    while (1) {
        printf("Ваше имя (не больше 10 букв)\n");
        printf(">>> ");
        scanf("%9s", pN);
        if (strlen(pN) < 10)
            break;
    }
    printf("\nПриветсвую, %s!", pN);
}