#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    short num; short * pNum = &num;
    fflush(stdout);
    srand(time(NULL));
    
    while (1) {
        *pNum = rand() % 21 - 10;
        printf("Автоматизация\n\n");
        printf("- Число: %hd\n", *pNum);
        printf("- %s\n", (*pNum != 0) ?
                        (*pNum > -1) ? "Положительно" : "Отрицательно"
                    : "Ноль");
        usleep(1500000); system("clear");
    }
}