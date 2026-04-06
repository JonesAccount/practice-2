#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

void fill_random(int *arr, size_t size, int min, int max) {
	if (NULL == arr || size == 0 || min > max ) { return; }

    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }

    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }

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

int max(int *arr, size_t size) {
	if (size == 0) { return INT_MIN; }

	int result = arr[0];

	for (size_t i = 1; i < size; i++) {
		if (arr[i] > result) {
			result = arr[i];
		}
	}

	return result;
}

int min(int *arr, size_t size) {
	if (size == 0) { return INT_MAX; }

	int result = arr[0];

	for (size_t i = 1; i < size; i++) {
		if (arr[i] < result) {
			result = arr[i];
		}
	}

	return result;
}

int main(void) {
	int arr[10];
	size_t size = sizeof(arr) / sizeof(arr[0]);
	fill_random(arr, size, 5, 25);
	sort_array(arr, size, 0);

	printf("Sort: ");
	for (size_t i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	int max_num = max(arr, size);
	printf("\nMax: %d", max_num);

	int min_num = min(arr, size);
	printf("\nMin: %d", min_num);


	getchar();

	return 0;
}
