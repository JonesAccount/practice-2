#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int arr[] = {4, 2, 8, 1};

    qsort(arr, 4, sizeof(int), compare);

    for (short i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}