#include <iostream>

namespace one {
    char letter = 'A';
}

namespace two {
    char letter = 'B';
}

namespace three {
    char letter = 'D';
}

int main() {
    std::cout << "\033[?25l";
    
    std::cout << one::letter << std::endl;
    std::cout << two::letter << std::endl;
    std::cout << three::letter << std::endl;
    
    std::cout << "\033[?25h";
    return 0;
}

//g++ 0514.cpp -o app && ./app