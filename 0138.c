#include <stdlib.h>
#include <stdio.h>

int main() {
    for (int i = 32; i <= 126; i++)
        printf(" Символ #%d: %c\n", i, i);
    
    getchar();
    getchar();
}