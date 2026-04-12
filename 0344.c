#include <stdio.h>

int main(void) {
    int arr[] = {5, 8, 2, 9, 2, 9, 0};
    
    *(arr + 5) += 1;
    (*(arr + 5))++;
    
    printf("%d\n", *(arr + 5));
    printf("%d\n", arr[5]);
    
    *(arr + 2) *= *(arr + 2);
    printf("%d", *(arr + 2));
    
    return 0;
}