#include <iostream>

int main() {
    std::string name;
    std::cout << "Your name: ";
    std::getline(std::cin, name);
    
    if (name.empty()) {
        std::cout << "Nothing!" << std::endl;
    } else {
        std::cout << "Your e-mail: " << name.append("@gmail.com") << std::endl;
#define NEWLINE "\n"
#define NOTHING ""

int main() {
    std::cout << "\033[?25l";
    
    for (int i = 1; i < 21; i++) {
        if (i < 10) { std::cout << "0"; }
        std::cout << i << " ";
        (i % 4 == 0) ? std::cout << NEWLINE : std::cout << NOTHING;
    }
    
    return 0;
}