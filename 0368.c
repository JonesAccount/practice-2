#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int arr[] = {7, 3, 8, 0};
    int *p[] = {&arr[0], &arr[1], &arr[2], &arr[3]};
    int *p1[5];
    *p1[3] = 30;
    
    int *p2[3] = {4, 7, 9};
    
    printf("%d\n", *p[2]);
    printf("%d\n", *p1[3]);
    
    return 0;
}