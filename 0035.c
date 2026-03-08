#include <stdio.h>

int main(void)
{
    char array[3];
    
    printf("- ");
    scanf(" %c", &array[0]);
    printf("- ");
    scanf(" %c", &array[1]);
    printf("- ");
    scanf(" %c", &array[2]);
    
    printf("%c, %c", array[0], array[2]);
}