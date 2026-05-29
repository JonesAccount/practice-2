#include <iostream>

void clear_screen(void) {
    std::cout << "\033[2J\033[H";
}

int main() {
    bool cursor_hide = false;
    while (1) {
        clear_screen();
        
        if (cursor_hide) {
            std::cout << "\033[?25l";
        } else {
            std::cout << "\033[?25h";
        }
        
        std::cout << "Hide cursor? [y/n]" << std::endl;
        
        switch (ch) {
            case 'y': cursor_hide = true;  break;
            case 'n': cursor_hide = false; break;
        }
        
    }
    
    return 0;
}