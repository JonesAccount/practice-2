#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    int arr[] = {sizeof(char), sizeof(short), sizeof(int), sizeof(float), sizeof(long long int), sizeof(long double)};
    
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nbytes: %zu", sizeof(arr));
    printf("\nbits: %zu", sizeof(arr) * 8);
    
    return 0;
}