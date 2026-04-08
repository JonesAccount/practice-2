#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    fflush(stdout);
    
    for (int i = 1, j = 1; i == 1; j++) {
        if ((j % 5) == 0) { system("clear"); }
        printf("Итерация %d\n", j);
        usleep(100000);
    }
    
    return 0;
}