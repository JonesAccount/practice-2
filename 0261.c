#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fill_random(int *arr, size_t size, int min, int max) {
static int seeded = 0;
if (!seeded) {
srand(time(NULL));
seeded = 1;
}

for (size_t i = 0; i < size; i++) {  
    arr[i] = rand() % (max - min + 1) + min;  
}

}

int main(void) {
int arr[10];

fill_random(arr, 10, 1, 10);  
  
for (int i = 0; i < 10; i++) {  
    printf("%d ", arr[i]);  
}  
  
return 0;

}