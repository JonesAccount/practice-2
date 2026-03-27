#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    fflush(stdout);
    char loading[5] = "#####";
    printf("\033[?25l");
    while (1) {
        for (int i = 0; i < 5; i++) {
            printf("\t%c\n", loading[i]);
            sleep(1);
        }
        
        sleep(1);
        system("clear");
        printf("\t#\n#\n#\n#");
        sleep(1);
        system("clear");
        printf("\t#\n#\n#");
        sleep(1);
        system("clear");
        printf("\t#\n#");
        sleep(1);
        system("clear");
        printf("\t#");
        sleep(1);
        system("clear");
        
    }
    return 0;
}