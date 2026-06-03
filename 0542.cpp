#include <iostream>

#define NEWLINE "\n"
#define NOTHING ""

int main() {
    std::cout << "\033[?25l";

    for (int i = 1; i < 21; i++) {
        if (i < 10) { std::cout << "0"; }
        std::cout << i << " ";
        (i % 4 == 0) ? std::cout << NEWLINE : std::cout << NOTHING;
    }

    return 0;
}