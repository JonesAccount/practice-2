#include <iostream>

int main() {
    std::cout << "\033[?25l";
    
    const std::string ST = "PI: ";
    const double PI = 3.146644;
    const int RADIUS = 70;
    std::cout << ST << PI * RADIUS << " cm.";
    
    return 0;
}