#include <iostream>
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
    
    return 0;
}