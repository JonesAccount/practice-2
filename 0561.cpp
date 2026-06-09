#include <iostream>

int main() {
    int *p = nullptr;
    
    int x = 0;
    p = &x;
    
    if (nullptr == p) {
        std::cout << "Unsuccessful!";
    } else {
        std::cout << "Successful!";
    }
    
    return 0;
}