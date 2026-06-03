#include <iostream>

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
    
    return 0;
}