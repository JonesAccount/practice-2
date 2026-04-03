#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
	printf("\033[?25l");
	srand(time(NULL));
	while (1) {
		int *size = (int *)malloc(sizeof(int) * 1);
		if (NULL == size) { return 1; }
		*size = (rand() % 10) + 1;

		// stek
		int arrStek[*size];
		for (int i = 0; i < *size; i++) { arrStek[i] = 0; }

		// heap
		int *arrHeap = (int *)malloc(sizeof(int) * *size);
		if (NULL == arrHeap) { return 1; }
		for (int i = 0; i < *size; i++) { arrHeap[i] = 0; }

		printf("Массив в стеке:\n");
		for (int i = 0; i < *size; i++) { printf("%d ", arrStek[i]); }

		printf("\n\nМассив в куче:\n");
		for (int i = 0; i < *size; i++) { printf("%d ", arrHeap[i]); }

		getchar(); system("clear");
		free(size); free(arrHeap);
	}

	return 0;
}
