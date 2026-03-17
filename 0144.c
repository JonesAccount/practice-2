#include <stdio.h>

int main(void) {
    int num;
    printf("——————————\n");
    printf("[?]");
    printf("\n——————————");
    for (int i = 0; i < 20; i++)
        printf("\b");
    scanf("%d", &num);
}