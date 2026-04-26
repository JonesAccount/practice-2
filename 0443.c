#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define ROWS 13
#define COLS 30
#define SIZE ROWS * COLS

int player_y = 6, player_x = 15;
int new_y, new_x;
bool running = true;

int snake_body[(ROWS * (COLS - 1)) - 1] = {0};

char map[ROWS][COLS] = {
    {"#############################"},
    {"#                           #"},
    {"#                           #"},
    {"#                           #"},
    {"#                           #"},
    {"#                           #"},
    {"#            008            #"},
    {"#                           #"},
    {"#                           #"},
    {"#                           #"},
    {"#                           #"},
    {"#                           #"},
    {"#############################"}
};

void render_map(void);
void move_snake(void);
char getch(void);
void clear_screen(void);
    
int main(void) {
    printf("\033[?25l");
    snake_body[0] = 1;
    snake_body[1] = 1;
    
    while (running) {
        clear_screen();
        render_map();
        move_snake();
    }
    
    clear_screen();
    return 0;
}

void render_map(void) {
    char *pointer_map = &map[0][0];
    
    printf("\n   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%c", *pointer_map);
        if ((i + 1) % COLS == 0) { printf("\n   "); }
        pointer_map++;
    }
    
}

void move_snake(void) {
    char ch = tolower(getch());
    
    new_y = player_y;
    new_x = player_x;
    
    switch (ch) {
        case 'w': new_y--; break;
        case 'a': new_x--; break;
        case 's': new_y++; break;
        case 'd': new_x++; break;
        case 'x': running = false;
    }
    
    if (map[new_y][new_x] != '#') {
        map[player_y][player_x] = ' ';
        player_y = new_y;
        player_x = new_x;
        map[player_y][player_x] = '8';
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

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}