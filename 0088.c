#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char arr[4];
    
    for (short i = 0; i < 4; i++) {
        printf("Символ %hi/4: ", i + 1);
        arr[i] = getchar(); getchar();
        system("clear");
    }
    
    printf("Получилось: ");
    for (short i = 0; i < 4; i++)
        printf("%c", arr[i]);
}