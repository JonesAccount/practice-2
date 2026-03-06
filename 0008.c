#include <stdio.h>

int main(void)
{
    int a = 6, b = 3; b++;
    int res1, res2, res3, res4;
    
    res1 = a + b; res2 = a - b;
    res3 = a * b; res4 = a / b;

    printf("Математические операции\n\n");
    printf("Числа: %d,", a); printf(" %d\n", b); 
    printf("\nСложение: %d\n", res1); printf("Вычитание: %d\n", res2);
    printf("Умножение: %d\n", res3); printf("Деление: %d\n", res4);
    
    return 0;
}