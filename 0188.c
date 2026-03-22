#include <stdio.h>
#include <stdlib.h>

typedef float ft;

typedef struct {
    char brand[50];
    int year;
    ft mileage;
} Car;


int main(void) {
    Car c[3];
    
    strcpy(c[0].brand, "BMW");
    c[0].year = 2005;
    
    strcpy(c[1].brand, "AUDI");
    c[1].year = 2010;
    
    strcpy(c[2].brand, "LADA");
    c[2].year = 2008;
    
    while (1) {
        c[0].mileage = rand() % 199901 + 100;
        c[1].mileage = rand() % 199901 + 100;
        c[2].mileage = rand() % 199901 + 100;
       
        int choice = (c[0].mileage < c[1].mileage) ? 0 : (c[1].mileage < c[2].mileage) ? 1 : 2;
        
        printf("Бренд: %s\n", c[choice].brand);
        printf("Год: %d г.\n", c[choice].year);
        printf("Пробег: %.1f км.", c[choice].mileage);
        
        getchar();
        getchar();
        system("clear");
    }
    
    return 0;
}