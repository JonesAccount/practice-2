#include <stdio.h>

int main(void) {
    int arr[] = {5, 8, 2, 9, 2, 7, 9, 3};
    
    for (int i = 0; i < 9; i++) {
        if (i == 0) {
            printf("• %d", *(arr - 1));
            printf("\n---------------\n");
        }
        
        printf("• %d\n", *(arr + i));
        if (i == 7) { printf("---------------\n"); }
    }
    
    return 0;
}