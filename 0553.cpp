#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <ctime>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GRAY "\033[90m"
#define N "\n"

char choice_player(void);
char choice_computer(void);
void check_win(char choice_p, char choice_c);
void clear_screen(void);
char getch(void);
void choice_text(char ch);
void wait(void);

int main(int argc, char *argv[]) {
    std::cout << "\033[?25l";
    srand(time(NULL));
    
    while (1) {
        char choice_p, choice_c;
        choice_p = choice_player();
        if (choice_p == 'x') { break; }
        choice_c = choice_computer();
        wait();
        check_win(choice_p, choice_c);
        wait();
        clear_screen();
    }
    
    clear_screen();
    std::cout << "Thanks for playing :)" << "\033[?25h";
    return 0;
}

char choice_player(void) {
    char ch;
    
    while (1) {
        std::cout << PURPLE << "GAME: " << BOLD << "PAPER-STONE-SCISSORS " << GRAY << "[x] exit" << RESET << std::endl;
        std::cout << N << "[p] paper | [t] stone | [s] scissors" << std::endl;
        std::cout << N << "• Player choice: ";
        ch = tolower(getch());
        
        if (ch == 'p'  ch == 't'  ch == 's' || ch == 'x') {
            choice_text(ch);
            break;
        }
        
        clear_screen();
    }
    
    return ch;
}

char choice_computer(void) {
    char ch = rand() % 3 + 1;
    
    switch (ch) {
        case 1: ch = 'p'; break;
        case 2: ch = 't'; break;
        case 3: ch = 's'; break;
    }
    
    std::cout << "• Computer choice: ";
    
    choice_text(ch);
    
    return ch;
}

void check_win(char choice_p, char choice_c) {
    std::cout << "• ";
    switch (choice_p) {
        case 'p':
            if (choice_c == 'p') {
                std::cout << YELLOW << "NOBODY";
            } else if (choice_c == 't') {
                std::cout << GREEN << "PLAYER";
            } else {
                std::cout << RED << "COMPUTER";
            }
            break;
        case 't':
            if (choice_c == 'p') {
                std::cout << RED << "COMPUTER";
            } else if (choice_c == 't') {
                std::cout << YELLOW << "NOBODY";
            } else {
                std::cout << GREEN << "PLAYER";
            }
            break;
        case 's':
            if (choice_c == 'p') {
                std::cout << GREEN << "PLAYER";
            } else if (choice_c == 't') {
                std::cout << RED << "COMPUTER";
            } else {
                std::cout << YELLOW << "NOBODY";
            }
            break;
    }
    std::cout << " WON!" << RESET << std::endl;
}

void clear_screen(void) {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
}

char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);        
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);      
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    std::cin >> std::noskipws >> ch;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}

void choice_text(char ch) {
    switch (ch) {
        case 'p': std::cout << "paper" << std::endl; break;
        case 't': std::cout << "stone" << std::endl; break;
        case 's': std::cout << "scissors" << std::endl; break;
    }
}

void wait(void) {
    std::cout << N << "[enter]" << std::endl;
    std::cin.get();
}