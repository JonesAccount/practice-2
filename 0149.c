#include <stdio.h>
#include <stdlib.h>

// переменные
unsigned short rows, cols;

int main(void) {
    while (1) {
        printf("Введите количество строк: ");
        scanf("%hd", &rows);
        printf("Введите количество столбцов: ");
        scanf("%hd", &cols);
        
        if (rows > 0 && cols > 0)
        	break;
        else
        	system("clear");
    }
    
    char list[rows][cols];
    
    return 0;
}