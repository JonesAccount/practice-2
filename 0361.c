#include <stdio.h>

int main(void) {
    int size = 100;
    void *si = &size;
    
    int arr[*(int *)si];
    for (int i = 0; i < size; i++) {
        if (((i + 1) % 2) == 0) { i[arr] = i; }
        
        if (((i + 1) % 3) == 0) { arr[i] = i; }
        
        *(arr + i) = i;
        
    }
    
    for (int i = 0; i < size; i++) {
        if (((i + 1) % 2) == 0) {
            printf("%d\n", arr[i]);
        } else if (((i + 1) % 3) == 0) {
            printf("%d\n", i[arr]);
        } else {
            printf("%d\n", *(arr + i));
        }
    }
    
    return 0;
}