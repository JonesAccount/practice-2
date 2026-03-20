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
    short counter_star = 0;
    
    char space[] = {"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    "};
    int len = strlen(space);
    
    for (int j = 0; j < 50; j++) {
        printf("\033[H\033[J");
        space[rand() % len] = STAR;
        counter_star++;
        for (int i = 0; i < len; i++) {
            printf("%c", space[i]);
            if ((i + 1) % 80 == 0) printf("\n");
        }
    }
    
    while (1) {
        short int element = rand() % 2;
        
        if (element == 0) {
            space[rand() % len] = VACUUM;
            counter_star--;
       } else {
            if (counter_star <= 50) {
                space[rand() % len] = STAR;
                counter_star++;
            }
        }
            
        
        printf("\033[H"); //
        for (int i = 0; i < len; i++) {
            printf("%c", space[i]);
            if ((i + 1) % 80 == 0) printf("\n");
        }
        usleep(500000);
    }
        
    
    return 0;
}