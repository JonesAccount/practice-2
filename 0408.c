#include <stdio.h>

int main(void) {
    char *arr[5];
    
    printf("Имя 1: ");
    scanf("%10s", *(arr));
    
    while (getchar() != '\n');
    
    for (int i = 0; i < 5; i++) {
        printf("%s\n", *(arr + i));
    }
    
    return 0;
}