#include <iostream>

void foo(int n) {
    std::cout << n << std::endl;
}

void foo(int n, int n1) {
    std::cout << n + n1 << std::endl;
}

void foo(int n, int n1, int n2) {
    std::cout << n + n1 + n2 << std::endl;
}

int main() {
    
    foo(1);
    foo(1, 2);
    foo(1, 2, 3);
    
    return 0;
}