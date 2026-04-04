#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    int _2 = 0b1010;
    int _10 = 10;
    int _16 = 0xA;
    
    printf("Двоичная система: %d\n", _2);
    printf("Десятичная система: %d\n", _10);
    printf("Шестнадцатиричная система: %d\n", _16);
    
    return 0;
}