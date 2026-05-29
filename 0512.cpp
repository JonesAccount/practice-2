#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

#define NLINE std::cout << "\n\n";

using namespace std;

char getch(void);

int main() {
    std::cout << "\033[?25l";
    
    string boy = "Jake";
    std::string girl = "Emma";
    
    std::cout << "Boy or girl?";
    static char ch = tolower(getch());
    
    switch (ch) {
        case 'b': NLINE std::cout << boy << std::endl; break;
        case 'g': NLINE std::cout << girl << std::endl; break;
    }
    
    getch();
    
    std::cout << "\033[?25h";
    return 0;
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

//g++ 0512.cpp -o app && ./app