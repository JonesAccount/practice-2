#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    printf("Четные\n");
    for (int i = 1; i >= 0; i--) {
        for (int j= 1; j <= 9; j++) {
                if (i == 1) {
                    if (j % 2 == 0) printf("- \033[32m%d\033[0m\n", j);
                } else {
                    if (j % 2 != 0) printf("- \033[31m%d\033[0m\n", j);
                }
        }
        printf("\nНечетные\n");
    }
    printf("\033[1A");
    printf("\033[2K");

    return 0;
}