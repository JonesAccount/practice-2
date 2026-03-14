#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

int main(void) {
    bool separator = false;
    short cntr = 0;
    srand(time(NULL));
    
    while (1) {
        separator = rand() % 2;
        cntr++;
        printf("%hd | %s\n", cntr, (separator == 1) ? "true" : "false");
        usleep(1000000);
        system("clear");
    } 
}