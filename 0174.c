#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iso646.h>

int main(void) {
    fflush(stdout);
    printf("\033[?25l");
    short storage[4] = {0};
    
    while (storage[0] != 1) {
        printf("%hd | %hd | %hd | %hd\n",
        storage[0],
        storage[1],
        storage[2],
        storage[3]);
        
        storage[3]++;
        
        if (storage[1] == 1 and storage[2] == 1 and storage[3] == 1) {
            storage[0]++;
            storage[1] = 0;
            storage[2] = 0;
            storage[3] = 0;
        } else if (storage[2] == 1 and storage[3] == 1) {
            storage[1]++;
            storage[2] = 0;
            storage[3] = 0;
        } else if (storage[3] == 1) {
            storage[2]++;
            storage[3] = 0;
        }
        
        sleep(1);
        system("clear");
    }
    
    printf("%hd | %hd | %hd | %hd\n",
        storage[0],
        storage[1],
        storage[2],
        storage[3]);
    
    return 0;
}