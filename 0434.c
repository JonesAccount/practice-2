#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <iso646.h>

char getch(void);
void clear_screen(void);

void RED(char *);
void BLUE(char *);
void GREEN(char *);
void YELLOW(char *);
void WHITE(char *);

int main(void) {
    printf("\033[?25l\033[1m");
    
    char text[] = {"[1] RED\n[2] BLUE\n[3] GREEN\n[4] YELLOW\n[5] WHITE"};
    char ch = 0;
    
    void (*color[5])(char *) = {RED, BLUE, GREEN, YELLOW, WHITE};
    
    printf("%s", text);
    while (1) {
        ch = getch();
        
        if (ch == '1' or ch == '2' or ch == '3' or ch == '4' or ch == '5') { clear_screen(); }
        switch (ch) {
            case '1': color[0](text); break;
            case '2': color[1](text); break;
            case '3': color[2](text); break;
            case '4': color[3](text); break;
            case '5': color[4](text);
        }
    }
    
    return 0;
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

void RED(char *text) {
    printf("\033[31m" "%s", text);
}

void BLUE(char *text) {
    printf("\033[34m" "%s", text);
}

void GREEN(char *text) {
    printf("\033[32m" "%s", text);
}

void YELLOW(char *text) {
    printf("\033[33m" "%s", text);
}

void WHITE(char *text) {
    printf("\033[37m" "%s", text);
}