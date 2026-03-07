#include <stdio.h>

int main(void) {

  char breaks[] = "\n";

  if (1 == 1)
    printf("Yes 1%s", breaks);
  if (2 == 3 - 1)
    printf("Yes 2%s", breaks);
  if ((4 * 2) / 2 == (1 + 1) * 2)
    printf("Yes 3");

  return 0;
}
