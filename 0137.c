#include <stdlib.h>
#include <stdio.h>

int main() {
    int arr[3];
    *arr = 5;
    *(arr+1) = 7;
    *(arr+2) = 0;
    
    for (int i = 0; i < 3; i++) {
        printf("%d\n", arr[i]);
    }
}