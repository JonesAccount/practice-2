#include <stdio.h>

int main(void) {
    int size;
    
    printf("Количество элементов: ");
    scanf("%d", &size);
    
    int arr[size];
    
    for (int i = 0; i < size; i++) {
        printf("Элемент %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    printf("Среднее значение: %d", sum / size);
    
    return 0;
}