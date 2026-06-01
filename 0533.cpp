#include <iostream>
#include <cmath>

int main() {
    int x, y;
    x = y = 4;
    x++;
    
    int z = std::max(x, y);
    int d = std::min(x, y);
    
    std::cout << z << std::endl;
    std::cout << d << std::endl;
    
    int n1 = 3;
    int n2 = 5;
    int n3 = pow(n1, n2);
    int n4 = sqrt(n2);
    int n5 = abs(-8);
    int n6 = round(45.99);
    int n7 = ceil(7.2);
    int n8 = floor(4.24);
    std::cout << n3 << std::endl;
    std::cout << n4 << std::endl;
    std::cout << n5 << std::endl;
    std::cout << n6 << std::endl;
    std::cout << n7 << std::endl;
    std::cout << n8 << std::endl;
    
    int n9 = sqrt(48);
    std::cout << n9 << std::endl;
    
    std::cout << "\n\n" << round(5.6) << std::endl;
    std::cout << floor(5.6) << std::endl;
    
    return 0;
}

