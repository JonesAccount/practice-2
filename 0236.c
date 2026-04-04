#include <locale.h>
#include <stdio.h>

#define BITES 8

void main(void) {
    char *locale = setlocale(LC_ALL, "");
    
    printf("\033[?25l");
    printf("\033[1m\033[33mBYTES & BITES\n\033[0m");
    printf("- unsigned long long int: %zu (%d)\n", sizeof(unsigned long long int), sizeof(unsigned long long int) * BITES);
    printf("- long long int: %zu (%d)\n", sizeof(long long int), sizeof(long long int) * BITES);
    printf("- unsigned long int: %zu (%d)\n", sizeof(unsigned long int), sizeof(unsigned long int) * BITES);
    printf("- unsigned int: %zu (%d)\n", sizeof(unsigned int), sizeof(unsigned int) * BITES);
    printf("- long int: %zu (%d)\n", sizeof(long int), sizeof(long int) * BITES);
    printf("- int: %zu (%d)\n", sizeof(int), sizeof(int) * BITES);
    
    printf("\n- unsigned short: %zu (%d)\n", sizeof(unsigned short), sizeof(unsigned short) * BITES);
    printf("- short: %zu (%d)\n", sizeof(short), sizeof(short) * BITES);
    
    printf("\n- long double: %zu (%d)\n", sizeof(long double), sizeof(long double) * BITES);
    printf("- double: %zu (%d)\n", sizeof(double), sizeof(double) * BITES);
    printf("- float: %zu (%d)\n", sizeof(float), sizeof(float) * BITES);
   
    printf("\n- char: %zu (%d)\n", sizeof(char), sizeof(char) * BITES);
}