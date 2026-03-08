#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    short int num;
    printf("Вводи число от 1-10: ");
    scanf("%i", &num);
    
    if (num > 0 && num < 11) {
        switch (num) {
            case 3:
            case 5:
            case 9:
                system("clear");
                break;
            default:
                printf("%hd", num);
        }
    } else {
        printf("Не попал");
    }
    
    return 0;
}