#include <stdio.h>

int main(void) {
  int a, b;
  a = 5;
  b = 3;
  int res = a / b;

  const short int age = 10;
  const unsigned long long int cash = 374623325242;

  printf("Мне %d лет и у меня %lld денег", age, cash);
  return 0;
}
