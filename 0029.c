#include <stdio.h>

int main(void)
{
   float a, b;
   printf("Число 1: ");
   scanf("%f", &a);
   printf("Число 2: ");
   scanf("%f", &b);
   double res = a + b;
   printf("Результат: %.1f + %.1f = %.1lf\n\n", a, b, res);
}