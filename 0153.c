#include <stdio.h>
#include <unistd.h>

const char SYM = '*';
short counter = 0;

int main(void) {
    fflush(stdout);
    
    for (int i = 0; i < 20; i++) {
        if (i < 10)
            for (int i = 0; i < counter; i++)
                printf(" ");
            printf("%c\n", SYM);
            counter++;
        
        if (i > 10)
            for (int i = 0; i < counter; i++)
                printf(" ");
            printf("%c\n", SYM);
            counter++;
        
        usleep(100000);
    }
    
    return 0;
}