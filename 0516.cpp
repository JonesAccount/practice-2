#include <iostream>

namespace first  { int num = 1; }
namespace second { int number = 2; }
namespace three  { int num = 3; }

int main() {
    std::cout << "\033[?25l";
    
    using namespace three;
    using namespace second;
    
    std::cout << num << std::endl;
    std::cout << number << std::endl;
    
    std::cout << "\033[?25h";
    return 0;
}

//g++ 0516.cpp -o app && ./app