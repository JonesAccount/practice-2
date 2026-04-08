#include <stdio.h>

#define CAR 0b0001
#define HOUSE 0b0100
#define NOPE 0b0000

int main(void) {
    printf("\033[?25l");
    
    char param = 0b0010;
    
    if (param & CAR | param & HOUSE) {
        printf("Дам 1");
    } else if (param & CAR) {
        printf("Дам 2");
    } else if (param & HOUSE) {
        printf("Дам 3");
    } else if (param & NOPE) {
        printf("Не дам");
    }
    
    return 0;
}