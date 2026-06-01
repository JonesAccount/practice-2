#include <iostream>

#define NEWLINE "\n"
#define NOTHING ""
#define DOT "•"

int main() {
    std::cout << "\033[?25l";
    
    for (int i = 0; i < 2; i++) {
        if (!i) {
            std::cout << "ODD:" << std::endl;
            for (int j = 1; j < 10; j++) {
                std::string s = DOT + std::to_string(j) + NEWLINE;
                std::cout << ((j % 2 == 0) ? s : NOTHING);
            }
        } else {
            std::cout << NEWLINE << "EVEN:" << std::endl;
            for (int j = 1; j < 10; j++) {
                std::string s = DOT + std::to_string(j) + NEWLINE;
                std::cout << (!(j % 2 == 0) ? s : NOTHING);
            }
                
        }
        
    }
    
    
    return 0;
}