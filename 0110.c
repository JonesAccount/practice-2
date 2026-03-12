#include <stdio.h>

int main(void) {
    char st[] = "Hello \0 World!";
    printf("%d\n", strlen(st));
    
    char st2[] = "abracadabta";
    printf("%d\n", strlen(st2));
    
    char st3[50];
    scanf("%s", &st3);
    printf("\n%d", strlen(st3));
}