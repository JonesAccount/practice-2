#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

typedef enum { UP, DOWN, RIGHT, LEFT } Move;

int x = 1;
int y = 1;

char *map[] = {
    "################",
    "#              #",
    "#              #",
    "#              #",
    "#              #",
    "#              #",
    "#              #",
    "################"
};

void print_map(void) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 16; j++) {
            if (i == y && j == x) {
                printf("@");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
        
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

void move(Move *moving) {
    char ch = tolower(getch());
    
    switch (ch) {
        case 'w': *moving = UP; break;
        case 'a': *moving = LEFT; break;
        case 's': *moving = DOWN; break;
        case 'd': *moving = RIGHT; break;
    }
    
    switch (*moving) {
        case UP: y--; break;
        case DOWN: y++; break;
        case LEFT: x--; break;
        case RIGHT: x++; break;
    }
}

int main(void) {
    printf("\033[?25l");
    
    Move moving;
    
    while (1) {
        print_map();
        move(&moving);
        system("clear");
    }
    
    printf("\033[?25h");
    return 0;
}