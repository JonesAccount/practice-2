#include <stdio.h>

int main(void) {
    
    unsigned int res = 1, it;
    
    while (1 == 1) {
        printf("Число для факториала: ");
        scanf("%hd", &it);
        if (it > 1 && it < 10)
            break;
    }   
    
    for (short int i = 1; i != it + 1; i++) {
        res *= i;
    }
    
    printf("Результат: n! = %i", res);
    
    return 0;
}