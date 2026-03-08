#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    unsigned short int num;
    bool booling;
    
    printf("$ ");
    scanf("%hi", &num);
    
    if (num == 1) {
        booling = true;
    } else if (num == 0) {
        booling= false;
    }
    
    if (booling == true) {
        printf("Правда");
    } else if (booling == false) {
        printf("Ложь");
    }
    
    return 0;
}