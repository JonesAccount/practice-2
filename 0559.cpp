#include <iostream>

void swap(int &x, int &y);

int main() {
    int x = 1;
    int y = 2;
    
    swap(x, y);
    
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    
    return 0;
}

void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}