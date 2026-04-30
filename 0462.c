#include <stdio.h>

struct Car {
    int speed;
    char name[50];
};

int main(void) {
    struct Car car[3];
    
    car[0].speed = 100;
    strcpy(car[0].name, "bmw");
    
    struct Car plane;
    plane = car[0];
    
    plane.speed = 800;
    strcpy(plane.name, "boing");
    
    printf("Speed: %d\nBrend: %s\n", car[0].speed, car[0].name);
    printf("\nSpeed: %d\nBrend: %s", plane.speed, plane.name);
    
    return 0;
}