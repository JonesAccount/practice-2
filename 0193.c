#include <stdio.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 23 + 1
#define VIEW_Y 11
#define VIEW_X 25

typedef short int sint;

char map[ROWS][COLS] = {
    "########################",
    "#                      #",
    "#                      #",
    "#                      #",
    "#           @          #",
    "#                      #",
    "#                      #",
    "#                      #",
    "#                      #",
    "########################"    
};

sint player_y = 4, player_x = 12;
sint new_y, new_x;
sint half_y = VIEW_Y / 2;
sint half_x = VIEW_X / 2;
sint my, mx;
char input;
bool hasFood = false;

void show_map(void);
void move(void);
char getch(void);
void draw_tile(char tile);
void add_food(void);

int main(void) {
    srand(time(NULL));
    printf("\033[?25l");
    printf("\033[2J\033[H");
    add_food();
    while (1) {
        show_map();
        move();
    }
    system("clear");
    return 0;
}


void show_map(void) {
    for (int vy = 0; vy < VIEW_Y; vy++) {
        for (int vx = 0; vx < VIEW_X; vx++) {
            my = player_y - half_y + vy;
            mx = player_x - half_x + vx;

            if (vy == half_y and vx == half_x) {
                printf("@"); continue;
            }

            if (my < 0 or my >= ROWS or mx < 0 or mx >= COLS) {
                printf(" "); continue;
            }

            draw_tile(map[my][mx]);

        }
        printf("\n");
    }
}




void move(void) {
    input = tolower(getch());
    
    new_y = player_y;
    new_x = player_x;
    
    switch (input) {
        case 'w': new_y--; break;
        case 'a': new_x--; break;
        case 's': new_y++; break;
        case 'd': new_x++;
    }
    
    if (map[new_y][new_x] != '#') {
        map[player_y][player_x] = ' ';
        
        if (map[new_y][new_x] == '+')
            add_food();
        
        player_y = new_y;
        player_x = new_x;
        map[player_y][player_x] = '@';
        
        
    }
    
    printf("\033[%dA\033[0G", VIEW_Y);          
}


void draw_tile(char tile) {
    switch (tile) {
        case '#': printf("\033[107m\033[97m#\033[0m"); break;
        default:  printf("%c", tile);                  break;
    }
}


void add_food(void) {
    sint y, x;
    while (true) {
        y = rand() % 9; x = rand() % 22;
        if(map[y][x] == ' ') {
            map[y][x] = '+';
            break;
        }
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