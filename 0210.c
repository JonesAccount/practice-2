#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    int number, check;
    
    printf("Число: ");
    scanf("%d", &number);
    
    for (int i = 1; i <= number; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) { check++; }
        }
        if (check == 2) { printf("- %d\n", i); }
        check = 0;
    }
        
    return 0;
}