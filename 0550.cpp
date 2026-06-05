#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <limits>
#include <cctype>
#include <ctime>
#include <thread>
#include <chrono>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define N "\n"

using lli = long long;

void show_menu(void);
void show_balance(int balance);
int put_money(void);
void take_money(lli *balance);
void deposit(lli *balance);
char get_choice(void);
void reset_buffer(void);
char getch(void);
void wait(void);
void clear_screen(void);

int main() {
    std::cout << "\033[?25l";
    srand((unsigned)time(NULL));
    
    lli balance = 0;
    lli *pB = &balance;
    bool loop = true;
    char ch;
    
    while (loop) {
        show_menu();
        
        ch = get_choice();
        if (isdigit((int)(ch))) {
            clear_screen();
            switch (ch) {
                case '1': show_balance(balance);  break;
                case '2': balance += put_money(); break;
                case '3': take_money(pB);         break;
                case '4': deposit(pB);            break;
                case '5': loop = false;           break;
            }
            
            if (ch != '5') {
                std::cout << N << "[m] menu";
                wait();
            }
            
        }
        
        clear_screen();
    }
    
    std::cout << "You left a bank.";
    std::cout << "\033[?25h";   
    return 0;
}

void show_menu(void) {
    static const std::string title = "BANK OF VANGARD";
    
    // title
    std::cout << "• ";
    for (int i = 0; i < title.length(); i++) {
        std::cout << ((i + 1) % 2 == 0 ? RED : YELLOW);
        std::cout << BOLD << title[i] << RESET;
    }
    std::cout << " •" << std::endl;
    
    // choices
    static const std::string choices[] = {
        "[1] Show balance",
        "[2] Put money",
        "[3] Take money",
        "[4] Deposit",
        "[5] Exit"};
    
    for (int i = 0; i < sizeof(choices) / sizeof(choices[0]); i++) {
        std::cout << choices[i] << std::endl;
    }
}

void show_balance(int balance) {
    std::cout << "Balance: ";
    
    if (balance <= 100) {
        std::cout << RED;
    } else if (balance > 100 && balance <= 5000) {
        std::cout << YELLOW;
    } else {
        std::cout << GREEN;
    }
    
    std::cout << balance << "$" << RESET << std::endl;
}

int put_money(void) {
    lli temp = 0;
    std::cout << "PUT MONEY" << N << N << "How much: ";
    std::cin >> temp; 
    
    if (std::cin.fail()) {
        std::cin.clear();           
        std::cin.ignore(1000, '\n'); 
        std::cout << RED << "Unsuccessful!" << RESET << std::endl;
    } else {
        std::cout << GREEN << "Successful!" << RESET << std::endl;
    }
    
    return temp;
}

void take_money(lli *balance) {
    lli temp = 0;
    std::cout << "TAKE MONEY" << N << N << "How much: ";
    std::cin >> temp; 
    
    if (std::cin.fail()) {
        std::cin.clear();           
        std::cin.ignore(1000, '\n'); 
        std::cout << RED << "Unsuccessful!" << RESET << std::endl;
        return;
    }
    
    if (temp <= *balance) {
        *balance -= temp;
        std::cout << GREEN << "Successful!" << RESET << std::endl;
    } else {
        std::cout << RED << "Unsuccessful!" << RESET << std::endl;
    }
    
}

void deposit(lli *balance) {
    int days = 0;
    lli temp_balance = 0;
    float percent = rand() % (10 - 5 + 1) + 5;
    
    if (*balance < 1) {
        std::cout << "You do not have cash. Get out!" << std::endl;
        return;
    } else if (temp_balance > *balance) {
        std::cout << "Not enough money. Get out!" << std::endl;
        return;
    }
    
    std::cout << "DEPOSIT" << N << std::endl;
    std::cout << "How much money: ";
    std::cin >> temp_balance;
    
    std::cout << "How many days:\n";
    std::cin >> days;
    
    *balance -= temp_balance;
    
    for (int i = 0; i < days; i++) {
        clear_screen();
        std::cout << "Day " << i + 1 << "...";
        temp_balance *= (1 + percent / 100.0f);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    
    *balance += temp_balance;
}

char get_choice(void) {
    char ch = getch();
    return ch;
}

void reset_buffer(void) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);        
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);      
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    std::cin >> std::noskipws >> ch;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}

void wait(void) {
    char ch;
    while ((ch = tolower(getch())) != 'm') {}
}

void clear_screen(void) {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
}