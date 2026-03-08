#include <stdio.h>

void func(void) {
    printf("Функция вызвана\n");
}

int main(void) {
    
    short int i;
    
    while (1) {
        printf(">>> ");
        scanf("%i", &i);
        
        switch (i) {
            case 3:
                func();
                break;
        }
    }
    
    return 0;
}