#include <stdio.h>
#include <iso646.h>

int main(void) {
    short age; 
    scanf("%hd", &age);
    if (!(age >= 18))
        printf("Еще не взрослый");
    else if (age == 20 or age == 25)
        printf("Уже да");
    else
        printf("Взрослый");
    
    return 0;
}