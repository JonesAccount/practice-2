#include <stdio.h>

int main(void) {
    int x = 5;
    
    // блок 1
    {
        auto int x = 10;
        printf("%d\n", x);
    }
    
    // блок 2
    {
        printf("%d\n", x);
    }
    
    // блок 3
    {
        int x = 20;
        // вложенный блок
        {
            printf("%d\n", x);
            int x = 30;
            printf("%d\n", x);
        }
    }
    
    printf("%d\n", x);
    
    return 0;
}