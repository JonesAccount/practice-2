#include <locale.h>
#include <stdio.h>

int main(void) {
    char *locale = setlocale(LC_ALL, " ");
    
    printf("Привет, С!");
    
    return 0;
}