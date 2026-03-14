#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    const char *POLE[200];
    const char POINT[] = "@";
    
    fflush(stdout);
    srand(time(NULL));
    
    while (true) {
        short position = rand() % 193;
    
        for (short i = 0; i < 195; i++) {
            if (i == position)
                POLE[i] = POINT;
            else
                POLE[i] = "•";
        }
           
        short counter = 0;
        for (short i = 0; i < 192; i++) {
            if (counter != 15) {
                printf("%s ", POLE[i]);
                counter++;
            } else {
                printf("%s\n", POLE[i]);
                counter = 0;
            }
        }
        
        usleep(900000);
        system("clear");
    }
}