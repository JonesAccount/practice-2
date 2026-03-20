#include <stdio.h>
#include <iso646.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    fflush(stdout);
    char text[100];
    while (1) {
        printf("Твоя история: ");
        fgets(text, 100, stdin);
        if (strlen(text) < 20) {
            system("clear");
            printf("Нельзя меньше 20!\n");
            sleep(2);
            system("clear");
        } else
            break;
    }
    
    return 0;
}