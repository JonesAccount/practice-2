#include <termios.h>
#include <unistd.h>
#include <stdio.h>

void cube(void);
void rainbow(void);
void face(void);
void cube2(void);
void clear_screen(void);
char getch(void);

int main(void) {
    printf("\033[?25l");

    while (1) {
        printf("[1] Cube\n[2] rainbow\n[3] face\n[4] cube 2");

        char ch = getch();

        clear_screen();
        switch (ch) {
            case '1': cube(); break;
            case '2': rainbow(); break;
            case '3': face(); break;
            case '4': cube2(); break;
        }

        (void)getchar();
        clear_screen();
    }

    return 0;
}

void cube(void) {
    printf("\n\n\n\n\t   ");
    for (int i = 0; i < 4 * 8; i++) {
        printf("\033[41m \033[0m");
        if (((i + 1) % 8) == 0) { printf("\n\t   "); }
    }
}

void cube2(void) {
    printf("\n\n\n\n   ");
    for (int i = 0; i < 64; i++) {
        printf("\033[41m██\033[0m");
        if (((i + 1) % 8) == 0) { printf("\n   "); }
    }
}

void rainbow(void) {
    for (int i = 0; i < 10; i++) {
        char color = 41;

        for (int j = 0; j < 210; j++) {
            switch (color) {
                case 41: printf("\033[41m \033[0m"); break;
                case 42: printf("\033[42m \033[0m"); break;
                case 43: printf("\033[43m \033[0m"); break;
                case 44: printf("\033[44m \033[0m"); break;
                case 45: printf("\033[45m \033[0m"); break;
                case 46: printf("\033[46m \033[0m"); break;
                case 47: printf("\033[47m \033[0m"); break;
            }

            if (((j + 1) % 30) == 0) {
                printf("\n");
                color++;
            }

        }

    }
}

void face(void) {
        for (int i = 0; i < 120; i++) {

                switch (i) {
                        case 19: printf("\033[47m \033[0m"); break;
                        case 20: printf("\033[40m \033[0m"); break;
                        case 24: printf("\033[47m \033[0m"); break;
                        case 25: printf("\033[40m \033[0m"); break;
                        case 52: printf("\033[40m \033[0m"); break;
                        case 53: printf("\033[40m \033[0m"); break;
                        case 77: printf("\033[41m \033[0m"); break;
                        case 87: printf("\033[41m \033[0m"); break;
                        case 92: printf("\033[41m \033[0m"); break;
                        case 93: printf("\033[41m \033[0m"); break;
                        case 94: printf("\033[41m \033[0m"); break;
                        case 95: printf("\033[41m \033[0m"); break;
                        case 96: printf("\033[41m \033[0m"); break;
                        case 97: printf("\033[41m \033[0m"); break;
                        case 98: printf("\033[41m \033[0m"); break;
                        case 99: printf("\033[41m \033[0m"); break;
                        case 100: printf("\033[41m \033[0m"); break;
                        case 101: printf("\033[41m \033[0m"); break;
                        case 102: printf("\033[41m \033[0m"); break;
                        default: printf("\033[48;5;208m \033[0m");
                }

                if (((i + 1) % 15) == 0) { printf("\n"); }

        }

}

void clear_screen(void) {
    printf("\033[2J");
    printf("\033[H");
    fflush(stdout);
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