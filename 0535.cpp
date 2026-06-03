#include <iostream>

int main() {
<<<<<<< HEAD
    std::string name;
    std::cout << "your name: ";
    std::getline(std::cin, name);
    
    if (name.empty()) {
        std::cout << "write name!" << std::endl;
    } else {
        name.clear();
        std::cout << "welcome" << name << "!" << std::endl;
    }
=======
    int num;
    std::cout << "number: ";
    std::cin >> num;
    
    (num) ? std::cout << "True" : std::cout << "False";
>>>>>>> b5444e74e1b6d1012c6f63ae0b51db8b3e5e29ab
    
    return 0;
}