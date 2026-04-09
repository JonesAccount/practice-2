#include <stdio.h>

int main(void) {
    char arr[100] = {0};
    scanf("%99[^\n]", arr);
    getchar();
    printf("\n%s\n\n", arr);
    
    fgets(arr, sizeof(arr), stdin);
    printf("\n%s", arr);
}