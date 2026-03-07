#include <stdio.h>

int main(void)
{
    short int num;
    printf("Число: ");
    scanf("%d", &num);
    
    if (num == 3 || num < 4) {
        num = 0;
        printf("%d", num);
    } else {
        printf("Неверно");
    }
    
    return 0;
}