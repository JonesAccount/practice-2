#include <iostream>

std::string CutString(std::string f, std::string l);

int main() {
    std::string FirstName, LastName, FullName;
    
    std::cout << "First Name: ";
    std::cin >> FirstName;
    
    std::cout << "Last Name: ";
    std::cin >> LastName;
    
    FullName = CutString(FirstName, LastName);
    
    std::cout << "\nWelcome \033[33m" << FullName << "\033[0m!" << std::endl;
    
    return 0;
}

std::string CutString(std::string f, std::string l) {
    return f + " " + l;
}