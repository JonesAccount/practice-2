#include <iostream>

namespace first  { int num = 1; }
namespace second { int num = 2; }
namespace three  { int num = 3; }

int main() {
    std::cout << "\033[?25l";
    
    using namespace second;
    
    int num = 0;
    
    std::cout << num << std::endl;
    std::cout << first::num << std::endl;
    std::cout << second::num << std::endl;
    std::cout << three::num << std::endl;
    
    std::cout << "\033[?25h";
    return 0;
}

//g++ 0514.cpp -o app && ./app