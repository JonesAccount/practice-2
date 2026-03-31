#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

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

int main(void) {
    printf("\033[?25l");
    int number, check = 0;
    char choice;
    while (1) {
        system("clear");
        printf("[1] простые\n[2] составные\n");
        choice = getch();
        system("clear");
        printf("Число: ");
        scanf("%d", &number);
        
        for (int i = 1; i <= number; i++) {
            for (int j = 1; j <= i; j++) { if (i % j == 0) { check++; } }
            if (choice == '1') { if (check == 2) { printf("- %d\n", i); } }
            if (choice == '2') { if (check > 2) { printf("- %d\n", i); } }
            check = 0;
        }
        
        getchar(); getchar();
    }
        
    return 0;
}