#include <stdio.h>

short result = 1;
int fact(short num) {
    switch (num) {
        case 1:
            return 1;
            break;
        default:
            return num * fact(--num);
    }
    
}

int main(void) {
    short res = fact(5);
    printf("Факториал: n!%hd", res);
}