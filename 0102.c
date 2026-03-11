#include <stdio.h>
#include <stdbool.h>
#define show printf

int main(void) {
    
    char loading = '•';
    char * pL = &loading;
    bool selector = true;
    bool * pS = &selector;
    short length = 15;
    
    while (1) {
        // вперед
        if (*pS == true)
            for (short i = 0; i < length; i++)
                printf("%c", *pL);
        getchar();
        getchar();
        
        // назад
    }
    
    
    return 0;
}