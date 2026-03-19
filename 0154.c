#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define CLEAR system("clear")
#define WAIT sleep(1)
#define ONTIME fflush(stdout)
#define INPUT getchar()

long long int num1, num2, result;
char operator; char *pO = &operator;
const char* GRAY = "\033[1;30m";
const char* RESET = "\033[0m";


void welcome(void) {
    printf("\033[?25l");
    printf("\033[1;32m\n\n\n\t    MAZE GAME\033[0m\n");
}


void calculation(void) {
    printf("%s1. Enter the first and second\nnumbers separated by spaces.\n2. Enter the operator: +, -, *, /%s\n", GRAY, RESET);
    printf("\n[?] ");
    scanf("%lld%lld", &num1, &num2);
    
    printf("\n[?] ");
    scanf(" %c", pO);
    
    switch (*pO) {
        case '+':
            result = num1 + num2;
            printf("\n[%%] Result: %lld + %lld = %lld\n", num1, num2, result);
            printf("\nEnter");
            INPUT; INPUT; CLEAR;
            break;
        case '-':
            result = num1 - num2;
            printf("\n[%%] Result: %lld - %lld = %lld\n", num1, num2, result);
            printf("\nEnter");
            INPUT; INPUT; CLEAR;
            break;
        case '*':
            result = num1 * num2;
            printf("\n[%%] Result: %lld * %lld = %lld\n", num1, num2, result);
            printf("\nEnter");
            INPUT; INPUT; CLEAR;
            break;
        case '/':
            result = num1 / num2;
            printf("\n[%%] Result: %lld / %lld = %lld\n", num1, num2, result);
            printf("\nEnter");
            INPUT; INPUT; CLEAR;
            break;
    }
}


int main(void) {
    ONTIME;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    welcome();
    WAIT;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    CLEAR;
    do {
        calculation();
    } while (1 == 1);
    
    return 0;
}