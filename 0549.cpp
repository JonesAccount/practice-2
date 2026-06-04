#include <iostream>

int plus(void) { return 1; }

int main() {
    int num = 0;
    for (int i = 0; i < 10; i++) {
        std::cout << num << " ";
        num += plus();
    }
    
    std::cout << "\n\n";
    
    for (int i = 0; i < 10; i++) {
        std::cout << num << " ";
        num -= plus();
    }
    
    return 0;
}