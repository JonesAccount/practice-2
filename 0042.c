#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    short int num = -7;
    bool boo;
    
    if (num < 0)
        boo = false;
        
    if (boo)
        printf("Правда\n"); 
    else
        printf("Ложь\n");
        
    if (num)
        printf("Правда 2");    
    else
        printf("Ложь 2");
    
    return 0;
}