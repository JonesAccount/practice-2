#include <stdio.h>

int main(void) {

  int num;
  printf("Поля ввода: ");
  scanf("%d", &num);

  if (num % 2 == 0) {
    printf("Четное");
  } else if (num % 2 != 0) {
    printf("Нечетное");
  } else {
    printf("Ошибка :(");
  }

  return 0;
}
