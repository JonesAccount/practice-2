#include <stdio.h>

int main(void) {

  unsigned short int number;
  printf("Ввод: ");
  scanf("%hi", &number);

  if (number == 1) {
    printf("Ты лесби");
  } else {
    printf("Ты не лесби");
  }

  return 5;
}
