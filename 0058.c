#include <stdio.h>

int fac(unsigned short int num);

int main(void) {
  unsigned short int number;
  printf("Number: ");
  scanf("%hd", &number);
  int result = fac(number);
  printf("Factorial: n!%hd", result);
}

int fac(unsigned short int num) {
  short int res;
  for (short int i = 1; i < num + 1; i++)
    res *= i;
  return res;
}
