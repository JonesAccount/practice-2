#include <stdio.h>

#define Car struct {int speed; char name[]; }

int main(void) {
    Car car[3];
    
    struct Car plane = car;
    
    car[0].speed = 100;
    strcpy(car[0].name, "bmw");
    
    printf("Speed: %d\nBrend: %s", car[0].speed, car[0].name);
    
    return 0;
}