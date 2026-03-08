#include <stdio.h>
#include <unistd.h>

int main(void) {
    
    short int i = 0;
    
    while (i < 5) {
        i++;
        printf("  %hi\n", i);
        fflush(stdout);
        sleep(1);
    }
    
}