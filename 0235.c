#include <locale.h>
#include <stdio.h>

void main(void) {
    char *locale = setlocale(LC_ALL, " ");
    
    printf("Привет, С!");
}