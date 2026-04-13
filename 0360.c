#include <stdio.h>

int main(void) {
    int arr[] = {7, 4, 8};
    
    int x = 2[arr];
    printf("%d\n", x);
    
    int z = arr[2];
    printf("%d\n", z);
    
    int c = *(arr + 2);
    printf("%d\n", c);
    
    return 0;
}