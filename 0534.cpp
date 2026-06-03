#include <iostream>

int main() {
    std::string name;
    std::cout << "your name: ";
    std::getline(std::cin >> std::ws, name);
    
    if (name.length() < 2) {
        std::cout << "too short" << std::endl;
    } else if (name.length() > 8) {
        std::cout << "too long" << std::endl;
    } else if (name.empty()) {
        std::cout << "empty bro!" << std::endl;
    } else {
        std::cout << "perfert" << std::endl;
    }
    
    return 0;
}