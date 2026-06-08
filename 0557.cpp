#include <iostream>

int main() {
    const int size = 15;
    const int count = 5;
    std::string names[size];
    
    std::fill(names, names + (size), "Tony");
    std::fill(names, names + (size - count), "Daniel");
    std::fill(names, names + (size - (count * 2)), "Rick");
    
    for (std::string name : names) {
        std::cout << name << "\n";
    }
    
    return 0;
}