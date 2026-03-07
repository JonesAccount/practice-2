#include <stdio.h>

int main(void)
{
    long long int num;
    printf("Любое число / цифра: ");
    scanf("%lli", &num);
    
    if (num > -1 && num < 10) {
        printf("Это цифра");
    } else {
        printf("Это число");
    }
}