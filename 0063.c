#include <stdio.h>

int main() {
    float n = 1000;
    
    do {
        printf("%.1f\n", n);
        n /= 2;
    } while (n > 10);
    
    int num, coun = 0;
    
    printf("\n>>> ");
    scanf("%d", &num);
    
    do {
        
        printf("%d", coun);
        coun++;
        if (coun == 10)
            break;
        
    } while (num == 2);
    
}