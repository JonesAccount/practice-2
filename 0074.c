#include <stdio.h>
#include <stdlib.h>

char gal = ' ';
char gali[] = "✓";

short int step = 0;

char set_name(void);
int set_age(void);
float set_height(void);
char set_color(void);
void info(void);
void result(void);


struct Person {
    char name[50];
    int age;
    float height;
    char color[30];
};

struct Person girl;

int main(void) {
    
    info();
    
    set_name(); info();
    set_age(); info();
    set_height(); info();
    set_color(); info();
    
    return 0;
}


char set_name(void) {
    printf("$ ");
    scanf("%49s", &girl.name);
    step++;
    system("clear");
}


int set_age(void) {
    printf("$ ");
    scanf("%i", &girl.age);
    step++;
    system("clear");
}


float set_height(void) {
    printf("$ ");
    scanf("%f", &girl.height);
    step++;
    system("clear");
}


char set_color(void) {
    printf("$ ");
    scanf("%29s", &girl.color);
    step++;
    system("clear");
}


void info(void) {
    printf("Какая она?\n\n");
    if (step > 0) {
        printf("[%s] Имя\n", gali);
    } else {
        printf("[%c] Имя\n", gal);
    }
        
    if (step > 1) {
        printf("[%s] возраст\n", gali);
    } else {
        printf("[%c] возраст\n", gal);
    }
    
    if (step > 2) {
        printf("[%s] рост\n", gali);
    } else {
        printf("[%c] рост\n", gal);
    }
        
    if (step > 3) {
        printf("[%s] цвет кожи\n\n", gali);
    } else {
        printf("[%c] цвет кожи\n\n", gal);
    }
    
    switch (step) {
        case 4: result(); break;
    }
}


void result(void) {
    system("clear");
    
    printf("Твоя %s\n\n", girl.name);
    printf("• Ей %i лет\n", girl.age);
    printf("• Ее рост %.1f см.\n", girl.height);
    printf("• Цвет кожи %s\n", girl.color);
}