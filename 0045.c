#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char brk[] = "\n";
    
    // меню
    printf("Меню%s%s", brk, brk);
    printf("[0/1] Играть%s", brk);
    printf("[2] Продолжить%s", brk);
    printf("[3] Новая игра%s", brk);
    printf("[4/5] Выход%s%s", brk, brk);
   
    // действие
    short int num;
    printf(">>> ");
    scanf("%d", &num);
    
    switch (num) {
        case 0:
        case 1:
            system("clear");
            printf("Игра началась...");
            scanf("%i", &num);
            break;
        case 2:
            system("clear");
            printf("Продолжаем игру...");
            scanf("%i", &num);
            break;
        case 3:
            system("clear");
            printf("Создаем новую игру...");
            scanf("%i", &num);
            break;
        case 4:
        case 5:
            system("clear");
            printf("Выход из игры.");
            break;
    }
    

    return 0;
}