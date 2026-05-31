#include <iostream>

int main() {
    std::string name;
    std::string girlfriend_name;
    int age = 0;
    
    std::cout << "\nWhat is your age?" << std::endl;
    std::cin >> age;
    
    std::cout << "What is your name?" << std::endl;
    std::getline(std::cin >> std::ws, name);
    
    std::cout << "\nWhat is your girlfriend name?" << std::endl;
    std::getline(std::cin, girlfriend_name);
    
    std::cout << "\n\n\n\n" << name << " " << age << " y.o" << " has a girlfriend, her name is " << girlfriend_name << std::endl;
    std::cout << "\n\n\n\n";
    
    return 0;
}

// g++ 0530.cpp -o app && ./app