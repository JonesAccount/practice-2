#include <termios.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

// это для рендера шахты, в конец интерфейса
#define END_MINE_INTERFACE for (int iter = 0; iter < 8; iter++) { printf(N "                               "); } printf(N BOLD GRAY_WHITE "                              " RESET);

#define GRAY_WHITE "\033[30;47m"
#define GREEN "\033[32m"
#define UNLINED "\033[4m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define N "\n"

typedef unsigned long long int ULL;

// рендер базы
void render_base(ULL money);

// рендер шахты
void render_mine(void);

// логика шахты
void kernel_mine(bool input_validation, char player_action);

// страница с командами
void commands_book(void);

// вспомогательные функции
char getch(void);
void clear_screen(void);
void loading_screen(void);

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    // ПЕРЕМЕННЫЕ
    
    // флаги
    bool input_validation = true;
    bool running = true;
    char player_action = 0;
    
    // деньги игрока
    ULL money = 0;
    
    while (running) {
        input_validation = true;
        clear_screen();
        render_base(money);
        
        while (input_validation) {
            player_action = tolower(getch());
        
            switch (player_action) {
                case 'h':
                    clear_screen();
                    commands_book();
                    input_validation = false;
                    break;
                case 'm':
                    clear_screen();
                    loading_screen();
                    kernel_mine(input_validation, player_action);
                    input_validation = false;
                    break;
            }
        }
        
    }
    
    return 0;
}

void render_base(ULL money) {
    printf(BOLD GRAY_WHITE "           - БАЗА -           " RESET);
    
    printf(N BOLD "💰  " UNLINED "РЕСУРСЫ" RESET);
    printf(N BOLD "• Баксы: " GREEN "%llu" RESET, money);
    
    printf(N N "- - - - - - - - - - - - - - -");
    
    printf(N BOLD "📦  " UNLINED "РУДЫ" RESET);
    printf(N BOLD "• Уголь 0 шт." N "• Железо 0 шт." N "• Медь 0 шт.");
    printf(N N BOLD "• Место 0/500" N "• Ценность: 0 баксов");
    
    printf(N "                               ");
    printf(N "                               ");
    printf(N "                               ");
    printf(N "                               ");
    printf(N "                               ");
    
    printf(N BOLD GRAY_WHITE "h - для помощи                " RESET);

}

void kernel_mine(bool input_validation, char player_action) {
    while (input_validation) {
        clear_screen();
        render_mine();
        END_MINE_INTERFACE
        player_action = tolower(getch());
        switch (player_action) {
            case 'c':
                clear_screen();
                render_mine();
                printf("\n");
                for (int i = 0; i < 5; i++) {
                    printf("⛏️");
                    
                    usleep(50000);
                    fflush(stdout);
                }
                END_MINE_INTERFACE
                break;
            case 'b':
                clear_screen();
                input_validation = false;
                break;
            }
        }
}

void render_mine(void) {
    printf(BOLD GRAY_WHITE "          - ШАХТА -           " RESET);
    printf(N BOLD "Инвентарь");
    printf(N BOLD "• Кирка 1 lvl." N "• Динамит 0 шт.");
    
    printf(N "- - - - - - - - - - - - - - -");
    printf(N BOLD "Добыча");
    printf(N "• статус: бездействие");
    printf(N "• операция:");
    printf(N "- - - - - - - - - - - - - - -");
    
}

void commands_book(void) {
    printf(BOLD GRAY_WHITE "        - СПРАВОЧНИК -        " RESET);