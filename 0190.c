#include <stdio.h>

typedef struct {
    int age;
    float power;
} Animal;

int main(void) {
    Animal horse;
    
    horse.age = 12;
    horse.power = 455.5;
    
    printf("%d\n", horse.age);
    printf("%.1f", horse.power);
    
    return 0;
}