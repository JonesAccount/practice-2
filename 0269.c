#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int a = 0, b = 0;
    int target = 9;
    int arr[] = {2, 5, 9, 2, 7, 11, 15};
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (arr[i] + arr[j] == target) {
                a = arr[i];
                b = arr[j];
                break;
            }
        }
        
        if (!a == 0 || !b == 0) { break; }
    }
    
    if (a != 0) {
        printf("%d + %d = %d", a, b, target);
    } else {
        printf("Цель не найден");
    }
    
    return 0;
}