#include <iostream>

int main() {
    int count = 0;
    bool loop = true;
    while (loop) {
        for (;;count++) {
            if (count == 5) {
                loop = false; break;
            } else {
                std::cout << "+ " << count << std::endl;
            }
        }
    }
    
    std::cout << "= " << count;
    
    return 0;
}