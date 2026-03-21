#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bytes[8] = {0};
int target, counter = 0;
char text[256];
short len;


int main(void) {
    printf("\033[?25l");
    
    while (1) {
        printf("Текст: ");
        fgets(text, 255, stdin);
        len = strlen(text) / 2;
        target = len;
        while (counter != target) {
            counter++;
            bytes[7]++;
            for (int i = 7; i > 0; i--)
                if (bytes[i] == 2) {
                    bytes[i] = 0;
                    bytes[i-1]++;
                }
            if (bytes[0] == 1) break;
        }
        counter = 0;
        printf("Длина: %hd\n", len);
        printf("Длина в двоичном коде: ");
        for (int i = 0; i < 8; i++)
            printf("%d", bytes[i]);
        
        getchar();
        getchar();
        system("clear");
    }
    
    return 0;
}