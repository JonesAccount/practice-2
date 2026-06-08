#include <iostream>

int main() {
    std::cout << "\033[?25l";
    const std::string questions[] = {"What does int mean in C++?",
                                     "What does a for loop do?",
                                     "What is an array?",    
                                     "What is the difference between = and == in C++?"};
    
    const std::string options[][4] = {{"A. A data type for whole numbers", "B. A command to print text", "C. A type for decimal numbers", "D. A loop that repeats code"},
                                      {"A. Stores text in memory", "B. Repeats a block of code multiple times", "C. Creates a new variable", "D. Compares two values"},
                                      {"A. A type of loop", "B. A function that prints text", "C. A collection of elements stored under one name", "D. A comparison operator"},
    };
    
    const char answers[] = {'A', 'B', 'C'};
    
    std::cout << "\033[?25h";
    return 0;
}