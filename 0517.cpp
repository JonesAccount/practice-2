#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "\033[?25l";

    cout << "\n\n\n" << endl;
    
    cout << "\tHi" << endl;
    
    string laptop = "\tMacBook";
    cout << laptop << endl;
    
    cout << "\n\n\n" << endl;
    
    (void)getchar();
    
    cout << "\033[?25h";
    return 0;
}

// g++ 0517.cpp -o app && ./app