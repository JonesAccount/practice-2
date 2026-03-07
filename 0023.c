#include <stdio.h>

int main(void) {

  unsigned short int n;
  printf("Введите число: ");
  scanf("%hi", &n);

  if (n < 10) {
    printf("Однозначное число");
  } else if (n > 9 && n < 100) {
    printf("Двухзначное число");
  } else {
    printf("Многозначное число");
  }

  return 0;
}
