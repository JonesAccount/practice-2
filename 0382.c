#include <stddef.h>
#include <stdio.h>

void revers(int *p);
void arr_print(char *arr);

int main(void) {
    int x = 0;
    int *p = &x;
    scanf("%d", p);
    
    revers(p);
    
    char arr[] = {'s', '$', '+', '*'};
    arr_print(arr);
    
    return 0;
}

void revers(int *p) {
    for (int i = 1; i <= *p; i++) {
        printf("%d ", i);
    }
}

void arr_print(char *arr) {
    size_t size = sizeof(arr) / sizeof(arr[0]);
    printf("\n\n");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
}