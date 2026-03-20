#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(void) {
    fflush(stdout);
    srand(time(NULL));
    printf("\033[?25l");
    const char STAR = '.';
    const char VACUUM = ' ';
    
    char space[] = {"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            "};
    short len = strlen(space);
    
    for (int j = 0; j < 50; j++) {
        printf("\033[H\033[J");
        usleep(100000);
        space[rand() % len] = STAR;
        for (int i = 0; i < len; i++) {
            printf("%c", space[i]);
            if ((i + 1) % 60 == 0) printf("\n");
        }
    }
    
    return 0;
}