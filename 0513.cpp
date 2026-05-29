#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

using namespace std;

#define NLINE std::cout << "\n\n";

char getch(void);

int main() {
    cout << "\033[?25l";
    
    string boy = "Jake";
    string girl = "Emma";
    
    cout << "Boy or girl?";
    static char ch = tolower(getch());
    
    switch (ch) {
        case 'b': NLINE cout << boy << endl; break;
        case 'g': NLINE cout << girl << endl; break;
    }
    
    getch();
    
    cout << "\033[?25h";
    return 0;
}

char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);        
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);      
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    cin >> std::noskipws >> ch;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}

//g++ 0512.cpp -o app && ./app