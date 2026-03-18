#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAP_Y 50
#define MAP_X 53

#define VIEW_Y 11
#define VIEW_X 25


char map[MAP_Y][MAP_X] = {
    "#####################################################",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#                                                   #",
    "#####################################################"    
};

short player_y = 2, player_x = 4;
short new_y, new_x;
char input;

short half_y = VIEW_Y / 2;
short half_x = VIEW_X / 2;

short my, mx;

void draw_tile(char tile);
void show_map(void);
char getch(void);
void move(void);


int main(void) {
    printf("\033[?25l");
    while (1) {
        show_map();
        move();
        printf("\033[H");
    }
}


void show_map(void) {
    for (int vy = 0; vy < VIEW_Y; vy++) {
        for (int vx = 0; vx < VIEW_X; vx++) {
            my = player_y - half_y + vy;
            mx = player_x - half_x + vx;