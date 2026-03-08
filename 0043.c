#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num;
    printf("От 1 до 4: ");
    scanf("%d", &num);
    
    switch (num) {
        case 1:
            printf("Один");
            break;
        case 2:
            printf("Два");
            break;
        case 3:
            printf("Три"); 
            break;
        case 4:
            printf("Четыре"); 
            break; 
        default:
            printf("Нет");  
            
    }

    return 0;
}