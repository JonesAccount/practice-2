#include <stdio.h>

void cube(void) {
  char brk[] = "\n";
  for (short int i = 0; i < 4; i++)
    printf("00000000%s", brk);
  getchar();
}
