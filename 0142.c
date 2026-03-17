#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>

char map[18][41] = {
    "########################################",
    "#                                      #",
    "#   @    #######        #######        #",
    "#        #######        #######        #",
    "#        #######        #######        #",
    "#                                      #",
    "#    ##########        ##########      #",
    "#    #        #        #        #      #",
    "#    #        ##########        #      #",
    "#    #                        ###      #",
    "#    ##########        ##########      #",
    "#                                      #",
    "#        #######        #######        #",
    "#        #######        #######        #",
    "#    E   #######        #######        #",
    "#        #######        #######        #",
    "#                                      #",
    "########################################"
};

short player_y = 2, player_x = 4;
short enemy_y = 14, enemy_x = 5;
short new_y, new_x;
char input;

void move_enemy(void);
void show_map(void);
void moving(void);
char getch(void);


int main(void) {
    printf("\033[?25l");
    printf("\033[H");
    
    while (1) {
        show_map();
        moving();
        move_enemy();
        printf("\033[H");
    }
    
    return 0;
}


void moving(void) {
    input = tolower(getch());
    
    new_y = player_y;
    new_x = player_x;
    
    switch (input) {
        case 'w': new_y--; break;
        case 'a': new_x--; break;
        case 's': new_y++; break;
        case 'd': new_x++; break;
    }
    
    if (map[new_y][new_x] != '#') {
        map[player_y][player_x] = ' ';
        player_y = new_y;
        player_x = new_x;
        map[player_y][player_x] = '@';
    }
    
}


void move_enemy(void) {
    static int first_call = 1;
    if (first_call) {
        srand(time(NULL)); 
        first_call = 0;
    }

    short new_y = enemy_y;
    short new_x = enemy_x;
    
    int dir = rand() % 4;

    switch (dir) {
        case 0: new_y--; break; 
        case 1: new_y++; break;
        case 2: new_x--; break; 
        case 3: new_x++; break; 
    }
    
    if (map[new_y][new_x] != '#') {
        map[enemy_y][enemy_x] = ' '; 
        enemy_y = new_y;
        enemy_x = new_x;
        map[enemy_y][enemy_x] = 'E'; 
    }
}


void show_map(void) {
    for (int y = 0; y < 18; y++) {
        for (int x = 0; x < 40; x++) {
            if (map[y][x] == ' ')
                printf("\033[42m \033[0m");
            
            else if (map[y][x] == '@')
                printf("\033[42m\033[1;34m@\033[0m");
            
            else if (map[y][x] == 'E')
                printf("\033[42m\033[1;31mE\033[0m");
            
            else
                printf("\033[100m \033[0m");  
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