#include <iostream>

int num = 5;

int main() {
    
    int num = 6;
    std::cout << ::num << std::endl;
    std::cout << num;
    return 0;
}