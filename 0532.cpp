#include <iostream>
#include <cstring>
#include <termios.h>
#include <unistd.h>

#define RESET "\033[0m"

using B = bool;

void clear_screen() {
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

int main() {
    std::cout << "\033[?25l";
    const char *word = "tandem";
    const size_t size = strlen(word);
    std::string quess;
    B check;
    
    while (1) {
        clear_screen();
        check = 1;
        std::cout << "write: " << word << std::endl;
        std::cout << "\n[?] ";
        std::getline(std::cin >> std::ws, quess);
        
        for (int i = 0; i < size; i++) {
            if (word[i] != quess[i]) { check = 0; }
        }
        
        clear_screen();
        using namespace std;
        if (check) {
            cout << "\033[33mCorrect!";
        } else {
            cout << "\033[31mWrong!";
        }
        cout << RESET;
        
        getch();
    }
    
    std::cout << "\033[?25h";
    return 0;
}