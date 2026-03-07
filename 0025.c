#include <stdio.h>

int main(void) {

  unsigned short int number;
  printf("Number: ");
  scanf("%hi", &number);

  if (number < 3) {
    if (number == 1) {
      printf("This is 1");
    } else if (number == 2) {
      printf("This is 2");
    }
  } else {
    if (number == 3) {
      printf("This is 3");
    } else {
      printf("This is 4");
    }
  }

  return 0;
}
