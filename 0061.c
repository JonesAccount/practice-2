#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sorting(int nums);
void clear_sreen(void);

int arr[5] = {0};

int main(void) {

  srand(time(NULL));

  for (short int i = 0; i < 5; i++)
    arr[i] = rand() % 9 + 1;

  printf("Массив: ");
  for (short int i = 0; i < 5; i++)
    printf("[%i] ", arr[i]);

  sorting();
  printf("Сортировка: ");
  for (short int i = 0; i < 5; i++)
    printf("[%i] ", arr[i]);

  return 0;
}

void clear_screen(void) { system("clear"); }

void sorting(int nums) {}
