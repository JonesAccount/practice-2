#include <iostream>

typedef int N1;
using N2 = int;

int main() {
    std::cout << "\033[?25l";
    
    N1 n1 = 5;
    N2 n2 = 5;
    std::cout << sizeof(n1) << std::endl;
    std::cout << sizeof(n2) << std::endl;
    
    std::cout << "\033[?25h";
    return 0;
}