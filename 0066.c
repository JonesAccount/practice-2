#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

short int nums[4] = {0};
short int number;
short int counter = 0;

int add(void) {
    
    printf("\n\nЗаполни массив. Только цифры.\n>>> ");
    scanf("%hd", &number);
        
    switch (number) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            nums[counter] = number;
            counter++;
            break;
        default:
            printf("Некорректно");
            fflush(stdout);
            sleep(2);
            system("clear");
        }
    return 0;
}

int main(void) {
    
    while (1) {
        printf("Массив: ");
        for (short int i = 0; i < 4; i++) {
            printf("[%hd] ", nums[i]);
        }
        
        if (counter == 3 + 1) {
            printf("\n\nЗаполнен!");
            break;
        }    
        
        add();
        system("clear");
    }
    return 0;
}