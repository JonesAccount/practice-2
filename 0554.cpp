#include <iostream>

int main() {
    int numbers[] = {4, 8, 2, 8, 0};
    for (int number : numbers) {
        std::cout << number << " ";
    }
    
    std::cout << "\n" << std::endl;
    
    std::string names[] = {"Dolphin", "Maria", "Sandy", "Kezia"};
    for (std::string name : names) {
        std::cout << name << std::endl;
    }
    
    std::cout << "" << std::endl;
    
    int counter = 1;
    char letters[] = {'A', 'B', 'C', 'D', 'E'};
    for (char letter : letters) {
        std::cout << counter << ". " << letter << std::endl;
        counter++;
    }
    
    return 0;
}