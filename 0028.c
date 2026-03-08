#include <stdio.h>

int main(void)
{
   short int a, b;
   printf("Введите первое число: "); scanf("%hd", &a);
   printf("Введите второе число: "); scanf("%hd", &b);
   short int res = a + b;
   printf("Сложение: %hd + %hd = %hd", a, b, res);
   return 0;
}