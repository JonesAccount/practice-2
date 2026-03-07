#include <stdio.h>

int main(void)
{
   short int number;
   printf("Введите: ");
   scanf("%hd", &number);
   printf("Ввели: %hd", number);
   return 0;
}