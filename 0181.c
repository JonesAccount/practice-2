#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    struct Car {
        int price;
        char color[50];
        float ves;
    };
    
    struct Car bmw;
    bmw.price = 500;
    strcpy(bmw.color, "black");
    bmw.ves = 1.40;
    
    printf("%d\n", bmw.price);
    printf("%s\n", bmw.color);
    printf("%.2f", bmw.ves);
    
    return 0;
}