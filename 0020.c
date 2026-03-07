#include <stdio.h>

int main(void) {
  short int num;
  printf("Number: ");
  scanf("%hd", &num);

  if (num > 100) {
    printf("Too much");
  } else {
    printf("Too small");
  }

  return 0;
}
