#include <stdio.h>
#include <stdlib.h>

int bytes[8] = {0};
int player_target, counter = 0;

void show(void) {
    printf("\n8 bit: ");
    printf("\033[33m%d %d %d %d %d %d %d %d\033[0m",
    bytes[0],
    bytes[1],
    bytes[2],
    bytes[3],
    bytes[4],
    bytes[5],
    bytes[6],
    bytes[7]);
}


int main(void) {
    printf("\033[?25l");
    while (1) {
        printf("Input 0-255: ");
        scanf("%d", &player_target);
        while (counter != player_target) {
            counter++;
            bytes[7]++;
            
            for (int i = 7; i > 0; i--)
                if (bytes[i] == 2) {
                    bytes[i] = 0;
                    bytes[i-1]++;
                }
            
            if (bytes[0] == 1) break;
            
        }
        show();
        printf("\n\nEnter");
        getchar(); getchar();
        system("clear");
    }
    return 0;
}