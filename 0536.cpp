#include <iostream>

int main() {
    std::string name;
    std::cout << "Your name: ";
    std::getline(std::cin, name);
    
    if (name.empty()) {
        std::cout << "Nothing!" << std::endl;
    } else {
        std::cout << "Your e-mail: " << name.append("@gmail.com") << std::endl;
    }
    
    return 0;
}