#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    printf("\033[?25l");
    srand(time(NULL));
    
    while (1) {
        int var = rand() % (9 - 0 + 1) + 1;
        int *p = &var;
        
        printf("Указатель\np = %p", p);
        printf("\n\nПамять\nvar = %d", var);
        printf("\n\nАдрес\n%p", p);
        
        (void)getchar();
        system("clear");
    }
    
    return 0;
}