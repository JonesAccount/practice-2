#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort(int *arr, int flag);

int main(void) {
	printf("\033[?25l");
	srand(time(NULL));

	// создаем массив стековый
	int numbers[10] = {0};

	// заполняем массив случайными числами
	for (int i = 0; i < 10; i++) {
		numbers[i] = rand() % (100 - 1 + 1) + 1;
	}

	// показ исходного массива
	printf("Исходник:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", numbers[i]);
	}

	// сортировочная функция
	sort(numbers, 0); // принимает два аргумента: 1. массив 2. если единица то возрастанию, если 0 по убыванию

	// показ массива отсортированного по убыванию
	printf("\n\nПо убыванию:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", numbers[i]);
	}

	sort(numbers, 1);

	// показ массива отсортированного по возрастанию
	printf("\n\nПо возрастванию:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", numbers[i]);
	}

	getchar();

	return 0;
}

void sort(int *arr, int flag) {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if ((flag && arr[j] < arr[i]) || (!flag && arr[j] > arr[i])) {
				int temp = arr[i];
				arr[i] = arr[j];
			 	arr[j] = temp;
			}
		}
	}
}
