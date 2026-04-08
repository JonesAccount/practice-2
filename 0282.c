#include <stdio.h>

#define CAR 0b0001
#define HOUSE 0b0100
#define NOPE 0b0000

int main(void) {
    printf("\033[?25l");
    
    int n = 5;
    
    switch (n) {
        case 5: printf("Один\n");
        case 3: printf("Два\n"); 
        case 8: printf("Три\n");
        case 0: printf("Четыре");         
        
    }
    
    printf("\n\n");
    
    n = 777;
    
    switch (n) {
        case 5: printf("Один\n"); break;
        case 3: printf("Два\n"); break;
        case 8: printf("Три\n"); break;
        case 0: printf("Четыре");         
        default: printf("heh");
    }
    
    return 0;
}