#include <iostream>

int main() {
    int n1 = 5;
    float n2 = 5.5;
    char n3 = 'A';
    char n4[] = {"C plus plus"};
    bool n5 = true;
    double n6 = 99.9999;
    
    // int
    std::cout << "int: " << n1 << std::endl;
    
    // float
    std::cout << "float: " << n2 << std::endl;
    
    // char
    std::cout << "char: " << n3 << std::endl;
    
    // char array
    std::cout << "array: " << n4 << std::endl;
    
    // bool
    std::cout << "bool: " << n5 << std::endl;
    
    // double
    std::cout << "double: " << n6 << std::endl;
    
    return 0;
}