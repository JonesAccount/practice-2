#include <stdio.h>
#include <string.h>

int main(void) {
    char lens[50];
    printf("Текст: ");
    scanf("%s", lens);
    
    if (strlen(lens) > 5)
        printf("Больше чем 5");
    else if (strlen(lens) == 5)
        printf("Ровно 5");
    else
        printf("Меньше чем 5");
    
    return 0;
}