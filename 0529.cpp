#include <iostream>
#include <termios.h>
#include <unistd.h>

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

int main() {
    std::cout << "\033[?25l";
    clear_screen();
    
    int choice = 0;
    int howmany = 0;
    
    std::cout << "What do you want to order?" << std::endl;
    std::cout << "[1] Pizza\n[2] Burger\n[3] Kebab" << std::endl;
    std::cout << "\n[?]: ";
    std::cin >> choice;
    
    clear_screen();
    
    std::cout << "How many?" << std::endl;
    std::cout << "\n[?]: ";
    std::cin >> howmany;
    
    clear_screen();
    
    std::cout << "You ordered " << howmany;
    using namespace std;
    switch (choice) {
        case 1: cout << " pizza"  << endl; break;
        case 2: cout << " burger" << endl; break;
        case 3: cout << " kebab"  << endl; break;
        
    }
    
    while (1) { getch(); }
    
    std::cout << "\033[?25h";
    return 0;
}

// g++ 0529.cpp -o app && ./app