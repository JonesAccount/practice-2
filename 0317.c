#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    printf("\033[?25l");
    srand(time(NULL));
    
    while (1) {
        int arr[100] = {0};
        for (int i = 0; i < 100; i++) {
            arr[i] = rand() % (9 - 0 + 1) + 1;
            char *p = (char *)&arr[i];
        
            printf("Значение: x = %d", arr[i]);
            printf("\nЗанимает: %zu | %d", sizeof(arr[i]), sizeof(arr[i]) * 8);
            
            printf("\n\nАдресы байтов:\n");
            printf("1 байт: %p\n", p);
            printf("2 байт: %p\n", p + 1);
            printf("3 байт: %p\n", p + 2);
            printf("4 байт: %p\n", p + 3);
            
        
            (void)getchar();
            system("clear");
        }
    }
    
    return 0;
}