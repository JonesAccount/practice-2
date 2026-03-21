#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define CLEAR system("clear");

// переменные
char input;
bool _ = true;
char timeless[50];
short amount_cats = 0;

// структура
struct Cat {
    char *name;
    char *color;
    short *age;
    short *power;
};

struct Cat c[10];

// прототипы
char getch(void);
void create(void);
void show(void);

int main(void) {
    printf("\033[?25l");
    while (_) {
        printf("\n[C] Создать кошку | [Q] Выход\n");
        for (int i = 0; i < 30; i++)
            printf("—");
        
        show();
        
        char ch = getch();
        if ((unsigned char)ch < 128) 
            input = tolower(ch);
            
        switch (input) {
            case 'c': create(); break;
            case 'q': _ = false;
            default: CLEAR;
        }
    }
    CLEAR
    return 0;
}


void create(void) {
    CLEAR
    
    printf("1. Имя кошки: ");
    scanf("%s", timeless);
    c[amount_cats].name = malloc(50 * sizeof(char));
    strcpy(c[amount_cats].name, timeless);
    
    printf("2. Окрас: ");
    scanf("%s", timeless);
    c[amount_cats].color = malloc(50 * sizeof(char));
    strcpy(c[amount_cats].color, timeless);
    
    printf("3. Возраст: ");
    c[amount_cats].age = malloc(sizeof(short));
    scanf("%hd", c[amount_cats].age);
    
    printf("4. Сила: ");
    c[amount_cats].power = malloc(sizeof(short));
    scanf("%hd", c[amount_cats].power);
    
    amount_cats++;
    
    CLEAR
}


void show(void) {
    for (int i = 0; i < amount_cats; i++) {
        
        if (strcmp(c[i].color, "Красный") == 0) printf("\033[31m");
        if (strcmp(c[i].color, "Синий") == 0) printf("\033[34m");
        if (strcmp(c[i].color, "Зеленый") == 0) printf("\033[32m");
        if (strcmp(c[i].color, "Желтый") == 0) printf("\033[33m");
        
        printf("\n\n#%hd. %s\n", i + 1, c[i].name);
        printf("- Окрас: %s\n", c[i].color);
        printf("- Возраст: %hd лет/года\n", *c[i].age);
        printf("- Сила: %hd единиц", *c[i].power);
        
        printf("\033[0m");
    }
}

char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);       
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}