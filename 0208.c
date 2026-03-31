#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    int num;
    printf("Введите число: ");
    scanf("%d", &num);

    printf("\nКратные числа:\n", num);
    for (int i = 1; i <= 50; i++) {
        if (num % i == 0) {  
            printf("• %d\n", i);
        }
    }

    return 0;
}