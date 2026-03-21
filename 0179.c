#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void) {
    printf("\033[?25l");
    fflush(stdout);
    srand(time(NULL));
    
    int a, b;
    
    while (1) {
        printf("Переместительный закон сложения\n");
        printf("a + b = b + a\n");
        
        a = rand() % 100;
        b = rand() % 100;
        
        printf("\n%d + %d = %d + %d\n", a, b, b, a);
        printf("%s", (a + b == b + a) ? "True\n" : "False\n");
        
        sleep(1);
        system("clear");
    }
    
    return 0;
}