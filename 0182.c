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
    
    printf("Бмв\n%d\n", bmw.price);
    printf("%s\n", bmw.color);
    printf("%.2f", bmw.ves);
    
    struct Car audi = {1000, "red", 1.5};
    printf("\n\nАуди\n%d\n", audi.price);
    printf("%s\n", audi.color);
    printf("%.2f", audi.ves);
    return 0;
}