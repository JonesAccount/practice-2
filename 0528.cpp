#include <iostream>

int main() {
    std::string name;
    std::cout << "Tell me your name: ";
    std::cin >> name;
    std::cout << "\nNice too meet you " << name << "!" << std::endl;
    
    return 0;
}

// g++ 0528.cpp -o app && ./app