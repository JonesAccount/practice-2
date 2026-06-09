#include <iostream>

int main() {
    int size;
    std::cout << "size: ";
    std::cin >> size;
    
    int *array = new int[size];
    
    for (int i = 0; i < size; i++) {
        *(array + i) = i + 1;
        std::cout << array[i] << " ";
    }
    
    return 0;
}