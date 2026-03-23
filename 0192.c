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
    "# @                    #",
    "#                      #",
    "#                      #",
    "#                      #",
    "#                      #",
    "#                      #",
    "#                      #",
    "#                      #",
    "########################"    
};

sint player_y = 1, player_x = 2;
sint new_y, new_x;
sint half_y = VIEW_Y / 2;
sint half_x = VIEW_X / 2;
sint my, mx;
sint position_y, position_x;
sint current = 0;
char memory = ' ';
char input;

void show_map(void);
void move(void);
char getch(void);
void draw_tile(char tile);
void add_numbers(void);

int main(void) {
    srand(time(NULL));
    printf("\033[?25l");
    printf("\033[2J\033[H");
    add_numbers();
    while (1) {
        show_map();
        move();
        if (current == 10) break;
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
        
        if (map[new_y][new_x] == '0' && current == 0)
            current++;
        else if (map[new_y][new_x] == '1' && current == 1)
            current++;
        else if (map[new_y][new_x] == '2' && current == 2)
            current++;
        else if (map[new_y][new_x] == '3' && current == 3)
            current++;
        else if (map[new_y][new_x] == '4' && current == 4)
            current++;
        else if (map[new_y][new_x] == '5' && current == 5)
            current++;
        else if (map[new_y][new_x] == '6' && current == 6)
            current++;
        else if (map[new_y][new_x] == '7' && current == 7)
            current++;
        else if (map[new_y][new_x] == '8' && current == 8)
            current++;
        else if (map[new_y][new_x] == '9' && current == 9)
            current++;
        else
            memory = map[new_y][new_x];
        
        map[player_y][player_x] = memory;
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


void add_numbers(void) {
    for (int i = 0; i < 10; i++)
        while (true) {
            position_y = rand() % 9;
            position_x = rand() % 22;
            if (map[position_y][position_x] == ' ') {
                map[position_y][position_x] = '0' + i;
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