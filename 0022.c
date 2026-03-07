#include <stdio.h>

int main(void) {
  short int num = -4;

  if (num < 0) {
    num = 4;
    printf("...");
  }

  printf("%hi", num);
  return 0;
}
