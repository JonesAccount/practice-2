#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int size = 100;
    void *si = &size;
    
    long int arr[*(int *)si];
    
    printf("Массив 1:\n");
    for (int i = 0; i < size; i++) {
        void *address = arr + i;
        printf("%d|%p\n", i + 1, address);
        
    }
    
    system("clear");
    int arr4[*(int *)si];
    printf("\n");
    printf("Массив 2:\n");
    for (int i = 0; i < size; i++) {
        void *address = arr4 + i;
        printf("%d|%p\n", i + 1, address);
        
    }
    
    return 0;
}