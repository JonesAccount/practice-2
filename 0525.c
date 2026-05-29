#include <iostream>

using namespace std;

int main() {
    std::cout << "\033[?25l";
    
    string name = "Johnny";
    string age = "20 y.o";
    
    std::cout << "My name is " << name << ". I'm " << age;
    
    return 0;
}