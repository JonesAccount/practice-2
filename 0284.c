#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    fflush(stdout);
    
    for (unsigned long long int j = 1; 1; j += 3) {
        if ((j % 5) == 0) { system("clear"); }
        printf("Итерация %d\n", j);
        usleep(100000);
    }
    
    return 0;
}