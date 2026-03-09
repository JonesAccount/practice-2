#include <stdio.h>

struct Cat {
    char name[10];
    short int age;
    float ves;
};

int main() {
    
    struct Cat bob = {"Миша", 5, 2.0f};
    
    printf("Имя: %s\n", bob.name);
    printf("Возраст: %hd лет\n", bob.age);
    printf("Вес: %.1f кг.", bob.ves);
    
    return 0;
}