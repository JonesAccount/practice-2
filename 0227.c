#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int line = 1, index = 0, doIt = 0;

	int *arr = (int *)malloc(sizeof(int) * 1);
	if (NULL == arr) { return 1; }
	printf("Число: "); scanf("%d", &arr[0]);
	index++;

	while (true) {
		line++;
		int *tmp = realloc(arr, line * sizeof(int));
		if (NULL == tmp) { free(arr); return 1; }
		arr = tmp;

		printf("Число: "); scanf("%d", &doIt);
		if (doIt == 1) {
			break;
		} else {
			arr[index] = doIt;
			index++;
		}

	}

	printf("\n");
	printf("Вы ввели (%d чисел): ", index);
	for (int i = 0; i < index; i++) { printf("%d ", arr[i]); }

	printf("\nСумма: ");
	int sum = 0;
	for (int i = 0; i < index + 1; i++) { sum += arr[i]; }
	printf("%d", sum);

	free(arr); getchar(); getchar();

	return 0;
}
