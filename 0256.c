#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort_array(int *arr, size_t size, int ascending);

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
	sort_array(numbers, 10, 0); // принимает два аргумента: 1. массив 2. если единица то возрастанию, если 0 по убыванию

	// показ массива отсортированного по убыванию
	printf("\n\nПо убыванию:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", numbers[i]);
	}

	sort_array(numbers, 10, 1);

	// показ массива отсортированного по возрастанию
	printf("\n\nПо возрастванию:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", numbers[i]);
	}

	getchar();

	return 0;
}

void sort_array(int *arr, size_t size, int ascending) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if ((arr[j] < arr[i]) == ascending) {
				int temp = arr[i];
				arr[i] = arr[j];
			 	arr[j] = temp;
			}
		}
	}
}