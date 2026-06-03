#include <iostream>

int main() {
    std::string name_full, name_first, name_last;
    std::cout << "Your full name: ";
    std::getline(std::cin, name_full);
    name_first = name_last = name_full;
    
    size_t pos = name_full.find(' ');
    
    for (int i = 0; i < name_first.length(); i++) {
        if (pos != std::string::npos) {
            name_first.erase(pos);
            break;
        }
    }
    
    for (int i = 0; i < name_last.length(); i++) {
        if (pos != std::string::npos) {
            name_last.erase(0, pos);
            break;
        }
    }
    
    std::cout << "Full name: " << name_full << std::endl;
    std::cout << "First name: " << name_first << std::endl;
    std::cout << "Last name: " << name_last << std::endl;
    
    return 0;
}