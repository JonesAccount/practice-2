#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <limits>

void clear_screen(void);
void newgame(void);
int logic(const int number, short guess, int tries);

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

int main() {
    std::cout << "\033[?25l";
    srand((unsigned)(time(NULL)));
    
    while (1) {
        const int number = rand() % 100 + 1;
        short guess = 0;
        int tries = 0;
        tries = logic(number, guess, tries);
        std::cout << "\nYou won!\nThe number is " << number << "\nTries: " << tries << "\nPress [r]" << std::endl;
        std::cout << "=============================" << std::endl;
    }
    
    newgame();
    std::cout << "\033[?25h";
    return 0;
}

void clear_screen(void) {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
}

void newgame(void) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char ch; while ((ch = tolower(getch())) != 'r') {}
    clear_screen();
}

int logic(const int number, short guess, int tries) {
    do {
        std::cout << "======GUESS NUMBER GAME======" << std::endl;
        std::cout << "Guess 1-100: ";
        std::cin >> guess;
        tries++;
            
        if (guess < number) {
            std::cout << "Too low!\n";
        } else if (guess > number) {
            std::cout << "Too high!\n";
        }
    } while (guess != number);
    
    return tries;
}