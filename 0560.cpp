#include <iostream>

void print(const int array[], const int size) {
    for (int i = 0; i < 20; i++) {
        std::cout << "- ";
        std::cout << (i == 19 ? "\n" : "");
    }

    std::cout << "\nsize: " << size << std::endl;
    std::cout << "array: " << size << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " " << ((i + 1) % 10 == 0 ? "\n" : "");
    }
    
    for (int i = 0; i < 20; i++) {
        std::cout << (!i ? "\n" : "");
        std::cout << "- ";
        std::cout << (i == 19 ? "\n" : "");
    }
}

int main() {
    while (1) {
        static int size = 0;
        static int *array = new int[size];
        print(array, size);
        
        std::cout << "\n[?]: ";
        std::cin >> size;
        
        if (size < 51 && size > 0) {
            int *temp = new int[size];
            array = temp;
        } else {
            size = 0;
        }
        
        for (int i = 0; i < size; i++) {
            *(array + i) = i + 1;
        }
    
    }
    
    return 0;
}