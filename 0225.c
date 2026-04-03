#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define CLEAR system("clear");
#define WAIT getchar(); getchar();
#define NOARR printf("Массив пуст");

void commands(void);
void input(int *pCMD);


int main(void) {
    printf("\033[?25l");
    
    int *arr = NULL;
    int *tmp = NULL;
    
    int cmd = 0;
    int *pCMD = &cmd;
    
    bool doesTheArrayExist = false;
    int sizeArr = -1;
    
    while (1) {
        commands();
        input(pCMD);
        
        CLEAR
        switch (*pCMD) {
            case 0:
                return 0;
            
            case 1:
                if (!doesTheArrayExist) {
                    NOARR
                } else {
                    for (int i = 0; i < sizeArr + 1; i++) {
                        printf("%d ", arr[i]);
                    }
                }
                WAIT
                break;
            
            case 2:
                if (!doesTheArrayExist) {
                    arr = (int *)malloc(sizeof(int) * 1);
                    if (NULL == arr) {
                        printf("Память не выделилась в куче");
                        free(arr);
                        return 0;
                    } else { sizeArr++; doesTheArrayExist = true; }
                    printf("Число: ");
                    scanf("%d", &arr[sizeArr]);
                } else {
                    tmp = realloc(arr, sizeArr + 2 * sizeof(int));
                    if (NULL == tmp) {
                        printf("Ошибка");
                        free(arr);
                        return 1;
                    } else {
                        arr = tmp;
                        sizeArr++;
                    }
                    printf("Число: ");
                    scanf("%d", &arr[sizeArr]);
                }
                break;
            
            case 3:
                if (doesTheArrayExist) {
                    tmp = realloc(arr, (sizeArr + 2 - 1) * sizeof(int));
                    if (NULL == tmp) {
                        printf("Ошибка");
                        free(arr);
                        return 1;
                    } else {
                        arr = tmp;
                        sizeArr--;
                        printf("Последний элемент удален");
                    }
                } else { NOARR }
                WAIT
                break;
            
            case 4:
                if (doesTheArrayExist) {
                    free(arr);
                    printf("Массив очищен");
                    doesTheArrayExist = false;
                    sizeArr = -1;
                } else { NOARR }
                WAIT
        }
    }
    
    return 0;
}


void commands(void) {
    CLEAR
    printf("[0] Закрыть программу\n");
    printf("[1] Показать массив\n");
    printf("[2] Добавить элемент\n");
    printf("[3] Удалить последний элемент\n");
    printf("[4] Очистить массив\n\n");
}


void input(int *pCMD) {
    printf("[?] ");
    scanf("%d", pCMD);
}