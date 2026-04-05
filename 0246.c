#include <stdio.h>
#include <stdlib.h>

#define MLN 1000000

typedef unsigned long long int myint;

int main(void) {
    myint *arr = (myint *)calloc(MLN, sizeof(myint));
    if (NULL == arr) {
        printf("fuck!");
        return 1;
    }
    
    for (int i = 0; i < MLN; i++) {
        arr[i] = i + 1;
    }
    
    size_t arrsize = sizeof(arr[0]) * MLN;
    
    printf("%zu", arrsize);
    
    return 0;
}