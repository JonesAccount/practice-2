#include <iostream>
<<<<<<< HEAD
#include <ctype.h>

int main() {
    std::string name;
    std::cout << "your name: ";
    std::getline(std::cin, name);
    
    std::cout << name.at(0) << name.at(name.length() - 1) << std::endl;
    
    name.insert(2, "@");
    std::cout << name << std::endl;
    
    for (int i = 0; i < name.length(); i++) {
        if (name.find(' ')) {
            name.erase(i, i);
        }
    }
    
    std::cout << name << std::endl;
=======

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
    
>>>>>>> b5444e74e1b6d1012c6f63ae0b51db8b3e5e29ab
    
    return 0;
}