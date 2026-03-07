#include <stdio.h>

int main(void)
{
    short int num;
    printf("Любое число: ");
    scanf("%hd", &num);
    
    if (num > -1) {
        printf("Положительно");
    } else {
        printf("Отрицательно");
    }
}