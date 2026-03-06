#include <stdio.h>

int main(void)
{
    int a = 6, b = 3; b++;
    int res1, res2, res3, res4;
    
    res1 = a + b; res2 = a - b;
    res3 = a * b; res4 = a / b;

    printf("Математические операции\n\n");
    printf("Числа: %d,", a); printf(" %d\n", b); 
    printf("\nСложение: %d + %d = %d\n", a, b, res1);
    printf("Вычитание: %d - %d = %d\n", a, b, res2);
    printf("Умножение: %d * %d = %d\n", a, b, res3);
    printf("Деление: %d / %d = %d\n", a, b, res4);
    
    return 0;
}