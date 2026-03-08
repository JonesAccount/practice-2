#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main(void) {
    
    short int tree = 0, coin = 0, dot = 9, count = 0;
    bool mainloop = true;
    
    printf("-РЕСЫ-\n");
    printf("Дерево: %hi\nМонеты: %hi", tree, coin);
        
    printf("\n\n-КОМАНДЫ-\n");
    printf("[0] Рубить дерево\n[1] Продать дерево\n[2] Выход");
    
    while (mainloop) {
        
        printf("\n\n>>> ");
        scanf("%hd", &dot);
        
        switch (dot) {
            case 0:
                count++; tree += count;
                printf("+ %hi дерево", count);
                count--;
                break;
            case 1:
                tree *= 2; coin += tree; tree /= 2;
                printf("продано %hi дерева за ", tree);
                tree *= 2; printf("%hi монеты", tree);
                tree = 0;
                break;
            case 2:
                system("clear");
                mainloop = false;
                break;
            default:
                system("clear");
                printf("-РЕСЫ-\n");
                printf("Дерево: %hi\nМонеты: %hi", tree, coin);
        
                printf("\n\n-КОМАНДЫ-\n");
                printf("[0] Рубить дерево\n[1] Продать дерево\n[2] Выход");
        }
    }
    return 0;
}