#include <iostream>
<<<<<<< HEAD

int main() {
    std::string name;
    std::cout << "your name: ";
    std::getline(std::cin, name);
    int size = name.length();
    
    size_t pos = name.find(' ');
    for (int i = 0; i < name.length(); i++) {
        if (pos != std::string::npos) {
            name.erase(pos);
            break;
        }
    }
    
    std::cout << name << std::endl;
    
=======
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

#define NEWLINE "\n"
#define NOTHING ""
#define DOT "•"

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

void clear_screen() {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
}

int main() {
    std::cout << "\033[?25l";
    
    for (int x = 0; x <= 1; x++) {
        std::cout << (!x ? "ODD:" : "\nEVEN:") << std::endl;
        for (int y = 1; y < 10; y++) {
            const std::string s = DOT + std::to_string(y) + NEWLINE;
            std::cout << (((!x) ? (y % 2 == 0) : !(y % 2 == 0)) ? s : NOTHING);
        }
        
    }
    
    while (1) {
        char ch = tolower(getch());
        if (ch == 'q') { break; }
    }
    
    clear_screen();
    std::cout << "\033[?25l";
>>>>>>> b5444e74e1b6d1012c6f63ae0b51db8b3e5e29ab
    return 0;
}