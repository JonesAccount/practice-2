#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void error(void) {
    system("clear");
    while(getchar() != '\n');
    printf("Error input\n");
    sleep(1);
    system("clear");
}

int main(void) {
    short start, finish, step;
    fflush(stdout);
    while (1) {
        printf("Range Sequence Generator\n");
        printf("\nstart finish step: ");
        if (scanf("%hd%hd%hd", &start, &finish, &step) == 3) {
            if (step != 0) {
                for (short i = start; i < finish; i += step)
                    printf("- %hi\n", i);
                printf("\nEnter");
                getchar(); getchar();
                system("clear");
            } else
                error();
        } else
            error();
        
    }
    
    return 0;
}