#include <iostream>

#define RESET "\033[0m"
#define SQUARES s1, s2, s3, s4, s5, s6, s7, s8, s9

void print(int *colors, std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8, std::string s9);
void clear_screen(void);
int get_index(int *colors, std::string *squares);
int get_color(int *colors, std::string *squares, int index);

int main() {
    std::cout << "\033[?25l";
    
    int colors[] = {37, 37, 37, 37, 37, 37, 37, 37};
    std::string squares[] = {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"};
    
    while (1) {
        int index;
        int color;
        
        index = get_index(colors, squares);
        color = get_color(colors, squares, index);
        
        
        
        
        int h; std::cin >>h;
    }
    
    std::cout << "\033[?25h";
    return 0;
}

void print(int *colors, std::string *squares) {
    for (int i = 0; i < 9; i++) {
        std::cout << squares[i] << RESET << " ";
        std::cout << ((i + 1) % 3 == 0 ? "\n" : "");
    }
}

void clear_screen(void) {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
}

int get_index(int *colors, std::string *squares) {
    int temp;
    while (1) {
        print(colors, squares);
        std::cout << "\nWhich square do you want to paint?\n[?] ";
        std::cin >> temp;
            
        if (temp > 0 && temp < 10) {
            break;
        } else {
            clear_screen();
        }
    }
    
    return temp;
}

int get_color(int *colors, std::string *squares, int index) {
    int temp;
    while (1) {
        std::cout << "\nWhat color would you like?" << std::endl;
        std::cout << "\033[31m1\033[0m | " << "\033[32m2\033[0m | " << "\033[33m3\033[0m | " << "\033[34m4\033[0m | " << "\033[35m5\033[0m | " << "\033[36m6\033[0m | " << "\n[?] ";
        std::cin >> temp;
            
        if (temp > 0 && temp < 7) {
            break;
        } else {
            clear_screen();
            print(colors, squares);
            std::cout << "\nWhich square do you want to paint?\n[?] " << index << std::endl;
        }
    }
    
    return temp;
}