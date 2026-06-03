#include <iostream>

int main() {
    std::string name;
    std::cout << "your name: ";
    std::getline(std::cin, name);
    
    if (name.empty()) {
        std::cout << "write name!" << std::endl;
    } else {
        name.clear();
        std::cout << "welcome" << name << "!" << std::endl;
    }
    
    return 0;
}