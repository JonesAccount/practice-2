#include <stdio.h>

int main(void) {
  unsigned short int a, b;
  scanf("%hu", &a);
  scanf("%hu", &b);
  short int res = a + b;
  printf("Result: %d", res);
  return 0;
}
