#include <termios.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define SIZE 20
#define NLINE "\n"
#define PARAM_A p, size
#define PARAM_B int *p, const int size

void fill(PARAM_B);
void print(PARAM_B);
void sort(PARAM_B, int sort_speed);
void clear_screen(void);
char getch(void);

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));
    printf("\033[?25l");
    fflush(stdout);
    
    bool forever = true;
    
    {
        while (forever) {
            int nums[SIZE] = {0};
            const size_t size = sizeof(nums) / sizeof(nums[0]);
            int *p = nums;
            int sort_speed = 100000;
            
            clear_screen();
            fill(PARAM_A);
            print(PARAM_A);
        
            printf(NLINE "[s] - sort");
            printf(NLINE "[q] - quit");
            
            while (1) {
                char ch = tolower(getch());
                
                if (ch == 's') {
                    while (1) {
                        clear_screen();
                        print(PARAM_A);
                        
                        printf(NLINE "choose speed:" NLINE);
                        printf("[1] faster" NLINE); // 100000
                        printf("[2] middle" NLINE); // 1000000
                        printf("[3] slowly");       // 600000
                        
                        char speed = getch();
                        
                        if (speed == '1') {
                            sort_speed = 1000;
                            break;
                        } else if (speed = '2') {
                            sort_speed = 30000;
                            break;
                        } else if (speed = '3') {
                            sort_speed = 90000;
                            break;
                        }
                        
                    }
                    break;
                } else if (ch == 'q') {
                    printf("\033[?25h");
                    clear_screen();
                    exit(0);
                }
                
            }
            
            sort(PARAM_A, sort_speed);
        
            clear_screen();
            print(p, size);
            printf(NLINE "sort finished successful" NLINE);
            getch();
        }
    }
    
    printf("\033[?25h");
    return 0;
}

void fill(PARAM_B) {
    for (int i = 0; i < size; i++) {    
        while (1) {
            bool check_exist = false;
            int temp = rand() % 20 + 1;
            for (int j = 0; j < size; j++) {
                if (*(p + j) == temp) {
                    check_exist = true;
                    break;
                }
            }
            
            if (!check_exist) {
                *(p + i) = temp;
                break;
            }
            
        }
       
    }
}

void print(PARAM_B) {
    for (int i = 0; i < 16; i++) {
        if (!i || i == 15) {
            printf("\033[1;%dH+", i + 1);
        } else {
            printf("\033[1;%dH-", i + 1);
        }
        
        if (i == 15) { printf(NLINE "|"); }
    }
    
    for (int i = 0; i < size; i++) {      
        printf("%s%d", (*(p + i) < 10) ? "0" : "", *(p + i));
        if ((i + 1) % 5 == 0) {
            printf("|" NLINE "|");
        } else {
            printf(" ");
        }
    }
    
    for (int i = 0; i < 16; i++) {
        if (!i || i == 15) {
            printf("\033[6;%dH+", i + 1);
        } else {
            printf("\033[6;%dH-", i + 1);
        }
    }
    
    printf(NLINE);
}

void sort(PARAM_B, int sort_speed) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (p[i] < p[j]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                
                printf(NLINE "sorting..." NLINE);
                usleep(sort_speed);
                clear_screen();
                print(PARAM_A);
            }
        }
    }
}

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);       
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}