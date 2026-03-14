#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>




char map[16][29] = {
    "        #######            ",
    "        #  @  #            ",
    "#########     #########    ",
    "#       #     #       #    ",
    "#                     #    ",
    "#       #     #       #    ",
    "#########     #########    ",
    "        #     #       #    ",
    "        #     #       #    ",
    "#########     #########    ",
    "#                     #    ",
    "#                     #    ",
    "#                     #    ",
    "#                     #    ",
    "#######################    ",
    "                           "
};

// переменные
short player_y = 1, player_x = 11;
short new_y, new_x;
char input;

// отрисовка карты
void show_map(void);

// движение персонажа
void move(void);

// режим без enter
char getch(void);


int main(void) {
    printf("\033[44m");
    printf("\033[?25l");
    while (1) {
        show_map();
        move();
    }
    
    return 0;
}


void show_map(void) {
    for (int i = 0; i < 16; i++)
        printf("      %s\n", map[i]);
}


void move(void) {
    input = getch();
    
    new_y = player_y;
    new_x = player_x;
    
    if (input == 'w' || input == 'W') new_y--;
    if (input == 'a' || input == 'A') new_x--;
    if (input == 's' || input == 'S') new_y++;
    if (input == 'd' || input == 'D') new_x++;
    
    if (map[new_y][new_x] != '#') {
        map[player_y][player_x] = ' ';
        player_y = new_y;
        player_x = new_x;
        map[player_y][player_x] = '@';
    }
    system("clear");
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