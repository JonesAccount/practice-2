#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define STRONG "\033[1m"

typedef struct {
    char name[10];
    short hp;
    short dmg;
} Warrior;

void clearScreen(void) {
    printf("\033[2J"); 
    printf("\033[H");   
    fflush(stdout);    
}

int main(void) {
    fflush(stdout);
    printf("\033[?25l");
    
    Warrior w1,w2;
    
    strcpy(w1.name, "Antonio");
    w1.hp = 100;
    w1.dmg = 10;
    
    strcpy(w2.name, "Shakaal");
    w2.hp = 100;
    w2.dmg = 10;
    
    while (w1.hp > 0 && w2.hp > 0) {
        
        printf(STRONG RED "Воин: %s" BLUE "\tВоин: %s\n" RESET, w1.name, w2.name);
        printf(STRONG RED "ХП: %hd" BLUE "\t\tХП: %hd\n" RESET, w1.hp, w2.hp);
        printf(STRONG RED "Урон: %hd" RESET, w1.dmg);
        if (w1.dmg < 10) {
            printf("\t\t");
        } else {
            printf("\t");
        }
        printf(STRONG BLUE "Урон: %hd\n" RESET, w2.dmg);
        
        short whoWillHit = rand() % 2;
        
        if (whoWillHit == 1) {
            w1.dmg = rand() % 10 + 1;
            w2.hp -= w1.dmg;
        } else if (whoWillHit == 0) {
            w2.dmg = rand() % 10 + 1;
            w1.hp -= w2.dmg;
        }
        
        sleep(1);
        clearScreen();
        
    }
    
    clearScreen();
    if (w1.hp != 0) { printf(STRONG RED "КРАСНЫЙ ПОБЕДИЛ!"); }
    if (w2.hp != 0) { printf(STRONG BLUE "СИНИЙ ПОБЕДИЛ!"); }
    
    return 0;
}