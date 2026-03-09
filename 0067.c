#include <stdlib.h>
#include <stdio.h>
#include <time.h>

short int arr[5];
short int res;
short int num;


void clear_screen(void) {
    system("clear");
}


void enter(void) {
    printf("\n\nEnter");
    getchar(); getchar();
    clear_screen();
}


void sum(void) {
    clear_screen();
    
    res = 0;
    for (short int i = 0; i < 5; i++) {
        res += arr[i];
    }
    
    printf("Сумма чисел: %hi", res);
    enter();
}


void max(void) {
    clear_screen();
    
    res = arr[0];
    for (short int i = 0; i < 5; i++) {
        if (arr[i] > res)
            res = arr[i];
    }
    
    printf("Максимальное число: %hi", res);
    enter();
}


void min(void) {
    clear_screen();
    
    res = arr[0];
    for (short int i = 0; i < 5; i++) {
        if (arr[i] < res)
            res = arr[i];
    }
    
    printf("Минимальное число: %hi", res);
    enter();
}


int main(void) {
    short int choice;
    
    srand(time(NULL));
    
    for (short int i = 0; i < 5; i++) {
        num = rand() % 20 + 1;
        arr[i] = num;
    }
    while (1) {
        printf("Массив: ");
        for (short int i = 0; i < 5; i++) {
            printf("[%hd] ", arr[i]);
        }
    
        printf("\n\n1 | минимальное число\n");
        printf("2 | максимальное число\n");
        printf("3 | сумма чисел\n\n");
    
        printf(">>> ");
        scanf("%hi", &choice);
    
        switch (choice) {
            case 1: min(); break;
            case 2: max(); break;
            case 3: sum(); break;
        }
    }   
    
    return 0;
}