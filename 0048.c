#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int n;
    
    while (n != 5) {
        printf("Введи пять: ");
        scanf("%i", &n);
        
        if (n != 5)
            system("clear");
    }
    
    printf("\nПрограмма завершилась...");
    
    return 0;
}