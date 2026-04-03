#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int arrSize = 0, del = 0;
	printf("Размер массива: ");
	scanf("%d", &arrSize);

	int *arr = (int *)malloc(sizeof(int) * arrSize);
	if (NULL == arr) { return 1; }

	for (int i = 0; i < arrSize; i++) {
		printf("Элемент №%d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\n");
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}

	printf("\nКакое значение удалить: ");
	scanf("%d", &del);

	int newSize = 0;
	for (int i = 0; i < arrSize; i++) { if (arr[i] != del) { newSize++; } }

	// new array
	int *newArr = (int *)malloc(sizeof(int) * newSize);

	int counter = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] != del) {
			newArr[counter] = arr[i];
			counter++;
		}
	}

	for (int i = 0; i < newSize; i++) {
		printf("%d ", newArr[i]);
	}

	getchar();getchar();

	free(newArr); free(arr);

	return 0;
}
