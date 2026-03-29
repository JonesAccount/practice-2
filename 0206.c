#include <stdio.h>
#include <stdlib.h>

void print_binary(int n) {
    printf("binary: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main(void) {
    printf("\033[?25l");
    int n;
    while (1) {
        printf("num: ");
        scanf("%d", &n);
        print_binary(n);
        getchar(); getchar();
        system("clear");
    }
    return 0;
}