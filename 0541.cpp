#include <iostream>

int main() {
    int num;
    std::cout << "number: ";
    std::cin >> num;

    (num) ? std::cout << "True" : std::cout << "False";

    return 0;
}