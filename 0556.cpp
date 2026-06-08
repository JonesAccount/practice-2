#include <iostream>

int main() {
    const int size = 10;
    int numbers[size];
    
    for (int i = 0, j = 10; i < size; i++, j--) {
        std::fill(numbers, numbers + j, i);
    }
    
    for (int number : numbers) {
        std::cout << number << " ";
    }
    
    return 0;
}