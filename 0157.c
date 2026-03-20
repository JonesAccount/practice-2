#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
    char space[501];
    const char STAR = '.';
    const char VACUUM = ' ';
    
    // отрисовка с центра экрана
    for (int i = 0; i < 5; i++)
        printf("\n");
    
    printf("start");
    // заполнение вакуумом
    for (int i = 0; i < 500; i++)
        space[i] = VACUUM;
    
    // заполнение звездами
    for (int i = 0; i < 500; i++) {
        if (i < 25) space[i] = STAR;
        //if (i < 50) 
    }
    
    // показ скопления
    for (int i = 0; i < 500; i++)
        printf("%c", space[i]);
    
    
    return 0;
}