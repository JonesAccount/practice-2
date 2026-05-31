#include <iostream>

int main() {
    double x = 6.3;
    char ch = 'A';
    float num = (int)50.55;
    
    std::cout << x << std::endl;
    std::cout << (int) x << std::endl;
    std::cout << (float)x << std::endl;
    std::cout << (char)(x - 0.3 + 60) << std::endl;
    std::cout << (int)ch << std::endl;
    std::cout << num << std::endl;
    std::cout << (float)(num + 0.55) << std::endl;
    std::cout << (char)(72) << (char)(69) << (char)(76) << (char)(76) << (char)(79) << std::endl;
    
    int answers = 4;
    int test = 10;
    double result = (double)answers / test * 100;
    std::cout << result << "% score" << std::endl;
    
    return 0;
}

// g++ 0527.cpp -o app && ./app