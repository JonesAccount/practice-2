#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <iso646.h>

#define MAP_Y 32
#define MAP_X 57

#define VIEW_Y 11
#define VIEW_X 25

char map[MAP_Y][MAP_X] = {
    "########################################################",
    "########################################################",
    "########################################################",
    "########################################################",
    "########################################################",
    "########################################################",
    "########################################################",
    "################# @            #   #     ###############",
    "#####################  ######  #   #     ###############",
    "#################   #       #  #   #  ##################",
    "#################   ####### #            ###############",
    "#################    #   #  ##### ###    ###############",
    "#################    #      #     #      ###############",
    "#################    ###### ###   #      ###############",
    "#################         #  ###  #   ##################",
    "#################  #  ##     ###  #      ###############",
    "#################  #      #  ###  #      ###############",
    "###########################       #      ###############",
    "#################   ##   ##########  ## #################",
    "##################                   ##  ###############",
    "#################   ###################  ###############",
    "#################   ####    ##           ###############",
    "#################   #    ## ## ####### #################",
    "#####################  #### ## #####     ###############",
    "################# X      ##    #####     ###############",
    "########################################################",
    "########################################################",
    "########################################################",
    "########################################################",
    "########################################################",
    "########################################################",
    "########################################################",
};

short player_y = 7, player_x = 18;
short new_y, new_x;
char input;

short half_y = VIEW_Y / 2;
short half_x = VIEW_X / 2;

short my, mx;

void draw_tile(char tile);
void show_map(void);
char getch(void);
void move_player(void);

int main(void) {
    printf("\033[?25l");
    printf("\033[2J");
    while (1) {
        printf("\033[H");
        show_map();
        move_player();
    }
}

void show_map(void) {
    for (int vy = 0; vy < VIEW_Y; vy++) {
        for (int vx = 0; vx < VIEW_X; vx++) {
            my = player_y - half_y + vy;
            mx = player_x - half_x + vx;

            if (vy == half_y && vx == half_x) {
                printf("\033[42m\033[35m@\033[0m");
                continue;
            }

            if (my < 0 or my >= MAP_Y  or mx < 0 or mx >= MAP_X) {
                printf(" ");
                continue;
            }

            draw_tile(map[my][mx]);
        }
        printf("\n");
    }
}

void move_player(void) {
    input = tolower(getch());

    new_y = player_y;
    new_x = player_x;

    switch (input) {
        case 'w': new_y--; break;
        case 'a': new_x--; break;
        case 's': new_y++; break;
        case 'd': new_x++; break;
        case 'q': printf("\033[?25h\033[0m\n"); exit(0);
    }

    if (new_y >= 0 && new_y < MAP_Y &&
        new_x >= 0 && new_x < MAP_X &&
        map[new_y][new_x] != '#') {
        player_y = new_y;
        player_x = new_x;
    }
}

void draw_tile(char tile) {
    switch (tile) {
        case '#': printf("\033[100m\033[90m#\033[0m"); break;
        default:  printf("%c", tile);                  break;
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
