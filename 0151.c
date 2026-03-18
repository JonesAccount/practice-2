if (vy == half_y && vx == half_x) {
                printf("\033[42m\033[35m@\033[0m");
                continue;
            }
            
            if (my < 0  my >= MAP_Y  mx < 0 || mx >= MAP_X) {
                printf(" ");
                continue;
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
        case 'd': new_x++; break;
    }
    
    if (map[new_y][new_x] != '#') {
        map[player_y][player_x] = ' ';
        player_y = new_y;
        player_x = new_x;
        map[player_y][player_x] = '@';
    }
}


void draw_tile(char tile) {
    switch (tile) {
        case ' ': printf("\033[42m \033[0m");          break;  
        case '#': printf("\033[100m\033[90m#\033[0m"); break;
        default:  printf("%c", tile);                  break;
    }
}


char getch(void) {
    struct termios oldt, newt;
    char ch;
    
    tcgetattr(STDIN_FILENO, &oldt);       // сохранить настройки
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    // отключить буфер и эхо
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // восстановить настройки
    return ch;
}