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
            int *p = &arr[i];
        
            printf("Указатель\np = %p", p);
            printf("\n\nПамять\nvar = %d", arr[i]);
            printf("\n\nАдрес\n%p", p);
        
            (void)getchar();
            system("clear");
        }
    }
    
    return 0;
}